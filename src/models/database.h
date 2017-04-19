#ifndef DATABASE_H
#define DATABASE_H

#include <QtCore>
#include <QList>
#include <QString>

#include "table.h"

class Database {
public:
  explicit Database();
  ~Database();
 public:
  QString name;
  QString encoding;
  QList<Table *>tables;
};

#endif // DATABASE_H
