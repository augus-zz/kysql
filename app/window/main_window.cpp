#include "main_window.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    createActions();
    createMenus();
    createSidebarDockWindow();
    createSQLEditorDockWindow();
    createBottomDockWindow();

    setMinimumSize(160, 160);
    resize(480, 320);
}

MainWindow::~MainWindow()
{
}

void MainWindow::createActions()
{
}

void MainWindow::createMenus()
{
}

#ifndef QT_NO_CONTEXTMENU
void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
}
#endif // QT_NO_CONTEXTMENU

void MainWindow::createSidebarDockWindow()
{
  QDockWidget *dock = new QDockWidget(tr("sidebar"), this);
  dock->setAllowedAreas(Qt::LeftDockWidgetArea);
  QListWidget *customerList = new QListWidget(dock);
  customerList->addItems(QStringList()
                         << "John Doe, Harmony Enterprises, 12 Lakeside, Ambleton"
                         << "Jane Doe, Memorabilia, 23 Watersedge, Beaton"
                         << "Tammy Shea, Tiblanka, 38 Sea Views, Carlton"
                         << "Tim Sheen, Caraba Gifts, 48 Ocean Way, Deal"
                         << "Sol Harvey, Chicos Coffee, 53 New Springs, Eccleston"
                         << "Sally Hobart, Tiroli Tea, 67 Long River, Fedula");
  dock->setWidget(customerList);
  addDockWidget(Qt::LeftDockWidgetArea, dock);
}

void MainWindow::createSQLEditorDockWindow()
{
  QDockWidget *dock = new QDockWidget(tr("sql_editor"), this);
  sql_editor = new SQLEditor(dock);
  dock->setWidget(sql_editor);
  addDockWidget(Qt::RightDockWidgetArea, dock);
}

void MainWindow::createBottomDockWindow()
{
  QDockWidget *dock = new QDockWidget(tr("bottom"), this);
  QTableView *table_view = new QTableView(this);
  QStandardItemModel *model = new QStandardItemModel();
  model->setColumnCount(2);
  model->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("Card NO"));
  model->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("Name"));
  table_view->setModel(model);

  dock->setWidget(table_view);
  addDockWidget(Qt::BottomDockWidgetArea, dock);
}
