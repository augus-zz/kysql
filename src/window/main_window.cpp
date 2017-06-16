#include "main_window.h"

#include "../application.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    init();
}

MainWindow::~MainWindow()
{
}

void MainWindow::create_actions()
{
}

void MainWindow::create_menus()
{
}

#ifndef QT_NO_CONTEXTMENU
void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
}
#endif // QT_NO_CONTEXTMENU


void MainWindow::init()
{
  logger("MainWindow.init");
  setMinimumSize(400, 300);
  resize(900, 600);

  create_actions();

  create_menus();

  create_shortcuts();

  tab_widget = new QTabWidget();
  setCentralWidget(tab_widget);

  if(!(qobject_cast<Application *>qApp)->connections.isEmpty())
  {
    for( auto &connection :( qobject_cast<Application *>qApp)->connections )
    {
      show_tab_page(connection);
    }
  }
  else
  {
    show_tab_page(NULL);
  }
}

void MainWindow::show_tab_page(Connection *connection)
{
  logger("MainWindow.show_tab_page");
  if(connection == NULL)
  {
    ConnectionWindow *w = new ConnectionWindow(NULL, this);
    tab_widget->addTab(w, "New Connection");
    connection_windows.append(w);
  }
  else
  {
    DbViewer *w = new DbViewer(connection, this);
    db_viewers.append(w);
    tab_widget->addTab(w, connection->name.isEmpty() ? connection->host : connection->name);
  }
  // logger("Mainwindow.create_page");
  // QVBoxLayout *sidebar_layout = new QVBoxLayout;
  // QTreeWidget *db_tree = new QTreeWidget();


  // db_tree->setMinimumWidth(200);
  // db_tree->setMaximumWidth(300);
  // sidebar_layout->addWidget(db_tree);
  // SQLEditor *sql_editor = new SQLEditor();

  // QTableView *table_view = new QTableView();
  // QStandardItemModel *model = new QStandardItemModel();
  // model->setColumnCount(2);
  // model->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("Card NO"));
  // model->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("Name"));
  // table_view->setModel(model);

  // QVBoxLayout *query_layout = new QVBoxLayout;
  // query_layout->addWidget(sql_editor);
  // query_layout->addWidget(table_view);

  // QHBoxLayout *h_layout = new QHBoxLayout;
  // h_layout->addLayout(sidebar_layout);
  // h_layout->addLayout(query_layout);

  // QWidget *page = new QWidget();
  // page->setLayout(h_layout);
  // tab_widget->addTab(page, connection == NULL || connection->name.isNull() ?
  //                   "New Connection" : connection->name);
}

void MainWindow::create_shortcuts()
{
  new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q), this, SLOT(close()));
  new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_N), this, SLOT(new_connection()));
  new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_W), this, SLOT(close_tab_page()));
}

void MainWindow::new_connection()
{
  logger("new connection");
  ConnectionWindow *w = new ConnectionWindow(NULL, this);

  tab_widget->addTab(w, "New Connection");
  tab_widget->setCurrentWidget(w);
  connection_windows.append(w);
}

void MainWindow::close_tab_page()
{
  logger("close window");
  QWidget *w = tab_widget->currentWidget();
  if(ConnectionWindow *cw = dynamic_cast<ConnectionWindow *>(w))
  {
    close_connection_page(cw);
  }
  else if(DbViewer *dw = dynamic_cast<DbViewer *>(w))
  {
    close_viewer_page(dw);
  }
}

void MainWindow::close_viewer_page(DbViewer *db_viewer)
{
  logger("close viewer window");
  db_viewers.removeOne(db_viewer);
  db_viewer->connection->close();
  db_viewer->close();

  tab_widget->removeTab(tab_widget->currentIndex());
  if(tab_widget->count() == 0)
  {
    close();
    return;
  }
}

void MainWindow::close_connection_page(ConnectionWindow *connection_window)
{
  logger("close connection window");
  connection_windows.removeOne(connection_window);
  connection_window->close();
  tab_widget->removeTab(tab_widget->currentIndex());

  if(tab_widget->count() == 0)
  {
    close();
    return;
  }
}

void MainWindow::save_connection()
{
  logger("save_connection");
  ConnectionWindow *w = (ConnectionWindow *) tab_widget->currentWidget();
  Connection *connection = new Connection;
  connection->host = w->txt_connection_host->text().isEmpty() ? "localhost" : w->txt_connection_host->text();
  connection->name = w->txt_connection_name->text().isEmpty() ? connection->host : connection->name;
  connection->port = w->txt_connection_port->text().toInt() == 0 ? 3306 : w->txt_connection_port->text().toInt();
  connection->username = w->txt_connection_username->text().isEmpty() ? "root" : w->txt_connection_username->text();
  connection->password = w->txt_connection_password->text();
  connection->log();
  connection_windows.removeOne(w);
  w->close();
  tab_widget->removeTab(tab_widget->currentIndex());

  (qobject_cast<Application *>qApp)->connections.append(connection);
  show_tab_page(connection);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
  logger("MainWindow.closeEvent");
  for(auto &connection: (qobject_cast<Application *>qApp)->connections)
  {
    //save
    (qobject_cast<Application *>qApp)->connections.removeOne(connection);
    delete connection;
  }
  QMainWindow::closeEvent(event);
}
