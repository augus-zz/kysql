#include "connection.h"

Connection::Connection()
{
  db_type = "QMYSQL";
  port = 3306;
  connected = false;
}

Connection::Connection(QString host, short port):host(host),port(port)
{
  db_type = "QMYSQL";
  this->host = host;
  this->port = port;

  connected = false;
}

Connection::~Connection()
{
  this->connected = false;
}

bool Connection::open()
{
  logger("Connection.open");
  init_db();
  if(db.open())
  {
    logger("Connection.open success");
    connected = true;
    return true;
  }
  return false;
}

bool Connection::close()
{
  db.close();
  return true;
}

void Connection::init_db()
{
  QStringList drivers = QSqlDatabase::drivers();
  logger(drivers.join(",").toStdString().c_str());

  db = QSqlDatabase::addDatabase(db_type);
  db.setHostName(host);
  db.setPort(port);
  db.setUserName(username);
  db.setPassword(password);
  db.setConnectOptions("MYSQL_OPT_CONNECT_TIMEOUT=5");
}

QStringList Connection::get_database_names()
{
  logger("Connection.get_database_names");
  QSqlQuery result = db.exec("show databases");

  QStringList db_names;
  while(result.next())
  {
    db_names.append(result.value(0).toString());
  }
  return db_names;
}

QList<Table *> Connection::get_database_tables(QString db_name)
{
  logger(QString("Connection.get_database_tables, db: %1").arg(db_name).toStdString().c_str());
  QSqlDatabase session_db = QSqlDatabase::cloneDatabase(db, db_name);
  session_db.setDatabaseName(db_name);
  session_db.open();

  QList<Table *> tables;
  QSqlQuery query("show tables;", session_db);
  query.exec();
  while(query.next())
  {
    QString table_name = query.value(0).toString();
    tables.append(get_table_details(&session_db, db_name));
  }

  return tables;
}

Table * Connection::get_table_details(QSqlDatabase *session_db, QString table_name)
{
    Table *table = new Table;
    table->name = table_name;
    QSqlQuery query(QString("desc %1").arg(table_name), *session_db);
    query.exec();
    // todo
    return table;
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
