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
  get_db_tables();

  db_widget->setColumnCount(1);

  QList<QTreeWidgetItem *> items;
  for(auto database : databases)
  {
    items.append(new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString(database->name))));
  }
  db_widget->insertTopLevelItems(0, items);
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
