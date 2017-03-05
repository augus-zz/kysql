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
#include <QListWidget>
#include <QTableView>
#include <QStandardItemModel>
#include <QShortcut>

#include "../utils/logger.h"

#include "sql_editor.h"
#include "connection_window.h"

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
  void create_actions();
  void create_menus();
  void create_page(Connection *connection);
  void init();
  void create_shortcuts();

  public slots:
    void new_connection();

  private:
  QTabWidget *tab_widget;
};

#endif // MAIN_WINDOW_H
