#include "main_window.h"

#include "../application.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    create_actions();
    create_menus();

    setMinimumSize(400, 300);
    resize(900, 600);

    init();
    create_shortcuts();
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
  //QMessageLogger(__FILE__, __LINE__, Q_FUNC_INFO).debug("test");
  // if((qobject_cast<Application *>qApp)->connections.isEmpty())
  // {
  //   qDebug() << "connection is empty";
  //   ConnectionWindow w(this);
  //   w.show_dialog(NULL);
  // }

  tab_widget = new QTabWidget();
  setCentralWidget(tab_widget);
  logger("create_page");

  Connection *connection = new Connection;
  (qobject_cast<Application *>qApp)->connections.append(connection);
  create_page(connection);
}

void MainWindow::create_page(Connection *connection)
{
  QVBoxLayout *sidebar_layout = new QVBoxLayout;
  QListWidget *customerList = new QListWidget();
  customerList->addItems(QStringList()
                         << "John Doe, Harmony Enterprises, 12 Lakeside, Ambleton"
                         << "Jane Doe, Memorabilia, 23 Watersedge, Beaton"
                         << "Tammy Shea, Tiblanka, 38 Sea Views, Carlton"
                         << "Tim Sheen, Caraba Gifts, 48 Ocean Way, Deal"
                         << "Sol Harvey, Chicos Coffee, 53 New Springs, Eccleston"
                         << "Sally Hobart, Tiroli Tea, 67 Long River, Fedula");

  sidebar_layout->addWidget(customerList);
  SQLEditor *sql_editor = new SQLEditor();

  QTableView *table_view = new QTableView();
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

  logger("show");

  QWidget *page = new QWidget();
  page->setLayout(h_layout);
  tab_widget->addTab(page, connection == NULL ? "New Connection" : connection->name);
}

void MainWindow::create_shortcuts()
{
  new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q), this, SLOT(close()));
  new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_N), this, SLOT(new_connection()));
}

void MainWindow::new_connection()
{
  logger("new connection");
  ConnectionWindow *w = new ConnectionWindow(this);

  Connection *connection = new Connection;
  (qobject_cast<Application *>qApp)->connections.append(connection);
  logger("append connection");
  w->init_widget(connection);
  tab_widget->addTab(w, "New Connection");
  tab_widget->setCurrentWidget(w);
 }

void MainWindow::close_page()
{
  logger("close window");
  ConnectionWindow *w = (ConnectionWindow *) tab_widget->currentWidget();
  (qobject_cast<Application *>qApp)->connections.removeOne(w->connection);
  delete w->connection;

  tab_widget->removeTab(tab_widget->currentIndex());
}
