#ifndef CONNECTION_H
#define CONNECTION_H

#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>

#include "../utils/logger.h"

class Connection {
 public:
  QString name;
  QString host;
  short port;

  QString username;
  QString password;

  int keep_alive;
  // QProxy proxy;

  QSqlDatabase db;
 public:
  Connection();
  Connection(QString host, short port);
  ~Connection();

  void log();

  bool open();
  bool close();
  QSqlQuery *query(QString &query_string);
  QSqlQuery *new_query();
};

#endif // CONNECTION_H
