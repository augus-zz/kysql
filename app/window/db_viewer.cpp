#include "db_viewer.h"

DbViewer::DbViewer(Connection *connection, QWidget *parent):QWidget(parent)
{
  this->connection = connection;
  init();
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
  //tab_widget->addTab(page, connection == NULL || connection->name.isNull() ? "New Connection" : connection->name);
}
