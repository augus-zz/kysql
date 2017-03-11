#ifndef DB_VIEWER_H
#define DB_VIEWER_H

#include <QtCore>
#include <QtGui>

#include <QTreeWidget>
#include <QTableView>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "sql_editor.h"
#include "../models/connection.h"

#include "../utils/logger.h"

class DbViewer: public QWidget {
  Q_OBJECT

 public:
  explicit DbViewer(Connection *connection, QWidget *parent = 0);
  ~DbViewer();
  void init();

 public:
   QTreeWidget *db_widget;
   SQLEditor *sql_editor;
   QTableView *table_view;
   Connection *connection;

 private:
};

#endif // DB_VIEWER_H
