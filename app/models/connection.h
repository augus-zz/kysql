#ifndef CONNECTION_H
#define CONNECTION_H

#include <QString>
#include <QSqlDatabase>

class Connection {
  private:
  QString host;
  short port;

  QString username
  QString password;

  int keep_alive;
  // QProxy proxy;
}

#endif # CONNECTION_H
