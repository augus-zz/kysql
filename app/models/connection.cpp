#include "connection.h"

Connection::Connection()
{
}

Connection::Connection(QString host, short port):host(host),port(port)
{
  this->host = host;
  this->port = port;
}

Connection::~Connection()
{

}

bool Connection::open()
{
  return false;
}

bool Connection::close()
{
  return false;
}

QSqlQuery *Connection::query(QString &query_string)
{
  return new QSqlQuery(query_string, db);
}

QSqlQuery *Connection::new_query()
{
  return new QSqlQuery(db);
}

void Connection::log()
{
  logger(QString("<Connection, name: %1, host: %2, port: %3, username: %4, password: %5>")
         .arg(name)
         .arg(host)
         .arg(port)
         .arg(username)
         .arg(password).toStdString().c_str());
}
