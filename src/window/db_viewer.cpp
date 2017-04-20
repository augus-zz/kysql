#include "db_viewer.h"

DbViewer::DbViewer(Connection *connection, QWidget *parent):QWidget(parent)
{
  this->connection = connection;
  init();
}

DbViewer::~DbViewer()
{
  if(connection)
  { connection->close(); }
}

void DbViewer::init()
{
  logger("DbViewer.init");
  QVBoxLayout *sidebar_layout = new QVBoxLayout;
  table_view = new QTreeWidget();
  table_view->setMinimumWidth(200);
  table_view->setMaximumWidth(300);

  database_cbx = new QComboBox();
  sidebar_layout->addWidget(database_cbx);
  sidebar_layout->addWidget(table_view);

  sql_editor = new SQLEditor();
  record_view = new QTableView();

  QVBoxLayout *query_layout = new QVBoxLayout;
  query_layout->addWidget(sql_editor);
  query_layout->addWidget(record_view);

  QHBoxLayout *h_layout = new QHBoxLayout;
  h_layout->addLayout(sidebar_layout);
  h_layout->addLayout(query_layout);

  setLayout(h_layout);

  init_db_info();
}

void DbViewer::init_db_info()
{
  logger("DbViewer.init_db_info");
  connection->log();
  if(!connection->connected)
  {
    connection->open();
  }

  if(!connection->connected)
  {
    logger("DbViewer.init_db_info open connection failed");
    return;
  }

  init_db_combox();
}

void DbViewer::init_db_combox()
{
  get_all_db();

  QStringList db_names;
  for(auto database : databases)
  {
    db_names.append(database->name);
  }
  connect(database_cbx, SIGNAL(currentIndexChanged(int)), this, SLOT(db_select(int)));
  database_cbx->addItems(db_names);
  current_database = databases.at(0);
}

void DbViewer::init_table_tree()
{
  get_db_tables();

  table_view->setColumnCount(1);
  table_view->setHeaderHidden(true);
  table_view->clear();
  QList<QTreeWidgetItem *> table_items;
  for(auto table : current_database->tables)
  {
    QTreeWidgetItem *item = new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString(table->name)));
    table_items.append(item);
    logger(QString("db_viewer.init_db_tree, table_name: %1").arg(table->name).toStdString().c_str());
  }
  connect(table_view, SIGNAL(itemClicked(QTreeWidgetItem *, int)), this, SLOT(tree_item_select(QTreeWidgetItem *, int)));
  connect(table_view, SIGNAL(itemDoubleClicked(QTreeWidgetItem *, int)), this, SLOT(table_query(QTreeWidgetItem *, int)));
  table_view->insertTopLevelItems(0, table_items);
}

bool DbViewer::get_all_db()
{
  logger("DbViewer.get_all_db");
  QStringList db_names = connection->get_database_names();
  logger(db_names.join(",").toStdString().c_str());
  for(auto name : db_names)
  {
    Database *db = new Database;
    db->name = name;
    databases.append(db);
  }
  return true;
}

bool DbViewer::get_db_tables()
{
  logger("DbViewer.get_db_tables");
  current_database->tables = connection->get_database_tables(current_database->name);
  return true;
}

void DbViewer::db_select(int idx)
{
  current_database = databases.at(idx);
  init_table_tree();
}

void DbViewer::tree_item_select(QTreeWidgetItem *tree_item, int column)
{
  logger(QString("tree_item selected, name: %1").arg(tree_item->text(0)).toStdString().c_str());
  QTreeWidgetItem *parent = tree_item->parent();
  if(NULL == parent)
  {
    // table
    logger("tree_item selected, table");
    if(tree_item->childCount() == 0)
    {
      table_select(tree_item, column);
    }
  }
  else
  {
    int depth = 1;
    while(NULL != parent->parent())
    {
      depth ++;
      parent = parent->parent();
    }

    if(1 == depth)
    {
      // field
      logger("tree_item selected, field");
      if(tree_item->childCount() == 0)
      {
      }
    }
    else
    {
      //unknown
      logger("tree_item selected, unknown");
    }
  }
}

void DbViewer::table_query(QTreeWidgetItem *tree_item, int column)
{
  logger(QString("DbViewer.table_query, name: %1").arg(tree_item->text(0)).toStdString().c_str());
  QTreeWidgetItem *parent = tree_item->parent();
  if(NULL == parent)
  {
    // table
    logger("table selected, table");
    query(tree_item->text(0));
  }
}

void DbViewer::query(QString table_name)
{
  logger(QString("DbViewer.query, db: %1, name: %2").arg(current_database->name).arg(table_name).toStdString().c_str());
  QSqlDatabase db = connection->get_db(current_database->name);
  QSqlTableModel *model = new QSqlTableModel(this, connection->get_db(current_database->name));
  model->setTable(table_name);
  model->setEditStrategy(QSqlTableModel::OnManualSubmit);
  model->select();

  Table table;
  table.name = table_name;
  connection->get_table_details(current_database->name, &table);
  int column_count = 0;
  for(auto column : table.columns)
  {
    model->setHeaderData(column_count++, Qt::Horizontal, QObject::tr(column->name.toStdString().c_str()));
  }
  record_view->setModel(model);
}

void DbViewer::table_select(QTreeWidgetItem *tree_item, int column)
{
  Table *table;
  for(auto tb : current_database->tables)
  {
    if(tb->name == tree_item->text(0))
    {
      table = tb;
      break;
    }
  }

  if(table && tree_item->childCount() == 0)
  {
    connection->get_table_details(current_database->name, table);
    QList<QTreeWidgetItem *> column_items;
    for(auto column : table->columns)
    {
      QTreeWidgetItem *item = new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString(column->name)));
      column_items.append(item);
    }
    tree_item->addChildren(column_items);
  }
}
