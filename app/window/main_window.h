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

#include "sql_editor.h"

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
  void createActions();
  void createMenus();
  void createSidebarDockWindow();
  void createSQLEditorDockWindow();
  void createBottomDockWindow();

  private:
  QDockWidget *sidebar_dock_window;
  QDockWidget *bottom_dock_window;

  private:
  SQLEditor *sql_editor;
};
