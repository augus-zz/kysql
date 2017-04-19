#ifndef DB_VIEWER_H
#define DB_VIEWER_H

#include <QtCore>
#include <QtGui>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QTableView>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QComboBox>

#include <QSqlError>
#include <QStringList>

#include "./sql_editor.h"
#include "../models/connection.h"
#include "../models/database.h"
#include "../utils/logger.h"

class DbViewer: public QWidget {
  Q_OBJECT

 public: explicit DbViewer(Connection *connection, QWidget *parent = 0); ~DbViewer();
   void init();

 public:
   QTreeWidget *table_view;
   QComboBox *database_cbx;
   SQLEditor *sql_editor;
   QTableView *record_view;
   Connection *connection;
   QList<Database *> databases;
   Database *current_database;
public slots:
   void db_select(int);
   void tree_item_select(QTreeWidgetItem *, int);
   void table_query(QTreeWidgetItem *, int);

public:
   void init_db_info();
   void init_db_combox();
   void init_table_tree();
   bool get_all_db();
   bool get_db_tables();
   void table_select(QTreeWidgetItem *, int);
   void query(QString table_name);
};

#endif // DB_VIEWER_H
