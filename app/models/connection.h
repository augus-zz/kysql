#ifndef CONNECTION_H
#define CONNECTION_H

#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include "../utils/logger.h"
#include "database.h"
#include "table.h"
#include "column.h"

class Connection
{
 public:
  explicit Connection();
  Connection(QString host, short port);
  ~Connection();

 public:
  QString name;
  QString db_type;
  QString host;
  short port;

  QString username;
  QString password;

  int keep_alive;
  // QProxy proxy;

  QSqlDatabase db;

  bool connected;

private:
  void init_db();

public:
  void log();
  bool open();
  bool close();
  QStringList get_database_names();
  QList<Table *> get_database_tables(QString db_name);
  QList<Column *> get_table_details(QString db_name, QString table_name);

  QSqlQuery *query(QString &query_string);
  QSqlQuery *new_query();
};

#endif // CONNECTION_H
