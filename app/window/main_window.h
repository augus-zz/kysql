#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QContextMenuEvent>
#include <QDockWidget>
#include <QTreeWidget>
#include <QTableView>
#include <QStandardItemModel>
#include <QShortcut>
#include <QCloseEvent>

#include "../utils/logger.h"

#include "sql_editor.h"
#include "connection_window.h"
#include "db_viewer.h"
#include "../models/connection.h"

class MainWindow : public QMainWindow
{
  Q_OBJECT

  public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

  protected:
#ifndef QT_NO_CONTEXTMENU
  void contextMenuEvent(QContextMenuEvent *event) override;
#endif // QT_NO_CONTEXTMENU

  private slots:

  private:
  void init();

  void create_actions();
  void create_menus();
  void show_tab_page(Connection *connection);
  void create_shortcuts();
  void closeEvent(QCloseEvent *event);
  void close_connection_page(ConnectionWindow *connection_window);
  void close_viewer_page(DbViewer *db_viewer);

  public slots:
    void new_connection();
    void save_connection();
    void close_tab_page();

  public:
    QList<ConnectionWindow *> connection_windows;
    QList<DbViewer *> db_viewers;

  private:
  QTabWidget *tab_widget;
};

#endif // MAIN_WINDOW_H
