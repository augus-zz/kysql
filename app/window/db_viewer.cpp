#include "db_viewer.h"

DbViewer::DbViewer(Connection *connection, QWidget *parent):QWidget(parent)
{
  this->connection = connection;
  init();
  init_db_info();
}

DbViewer::~DbViewer()
{
  if(connection)
  {
    connection->close();
  }
}

void DbViewer::init()
{
  logger("DbViewer.init");
  QVBoxLayout *sidebar_layout = new QVBoxLayout;
  db_widget = new QTreeWidget();

  db_widget->setMinimumWidth(200);
  db_widget->setMaximumWidth(300);
  sidebar_layout->addWidget(db_widget);
  sql_editor = new SQLEditor();

  table_view = new QTableView();
  QStandardItemModel *model = new QStandardItemModel();
  model->setColumnCount(2);
  model->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("Card NO"));
  model->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("Name"));
  table_view->setModel(model);

  QVBoxLayout *query_layout = new QVBoxLayout;
  query_layout->addWidget(sql_editor);
  query_layout->addWidget(table_view);

  QHBoxLayout *h_layout = new QHBoxLayout;
  h_layout->addLayout(sidebar_layout);
  h_layout->addLayout(query_layout);

  setLayout(h_layout);
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

  init_db_tree();
}

void DbViewer::init_db_tree()
{
  get_all_db();
  //get_db_tables();

  db_widget->setColumnCount(1);

  QList<QTreeWidgetItem *> db_items;
  for(auto database : databases)
  {
    QTreeWidgetItem *item = new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString(database->name)));
    db_items.append(item);
  }
  connect(db_widget, SIGNAL(itemClicked(QTreeWidgetItem *, int)), this, SLOT(db_select(QTreeWidgetItem *, int)));
  db_widget->insertTopLevelItems(0, db_items);
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
  for(auto db : databases)
  {
    db->tables = connection->get_database_tables(db->name);
  }
  return true;
}

void DbViewer::db_select(QTreeWidgetItem *tree_item, int column)
{
  logger(QString("tree_item selected, db_name: %1").arg(tree_item->text(0)).toStdString().c_str());
  QList <QTreeWidgetItem *>children = tree_item->takeChildren();
  for(auto item : children)
  {
    delete item;
  }
  QTreeWidgetItem *parent = tree_item->parent();
  if( NULL== parent)
  {
    // database
    logger("tree_item selected, database");
    Database * db;
    for(auto database : databases)
    {
      if(database->name == tree_item->text(0))
      {
        db = database;
        break;
      }
    }
    if(db)
    {
      QList<QTreeWidgetItem *> table_items;
      db->tables = connection->get_database_tables(db->name);
      for(auto tb : db->tables)
      {
        logger(QString("table name: %1").arg(tb->name).toStdString().c_str());
        QTreeWidgetItem *item = new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString(tb->name)));
        table_items.append(item);
      }
      tree_item->addChildren(table_items);
    }
  }
  else
  {
    int col = parent->indexOfChild(tree_item);
    if(0 == col)
    {
      //table
      logger("tree_item selected, table");
    }
    else if(1 == col)
    {
      //field
      logger("tree_item selected, field");
    }
    else
    {
      //unknown
      logger("tree_item selected, unknown");
    }
  }
}
