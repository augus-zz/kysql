#ifndef DATABASE_H
#define DATABASE_H

#include <QtCore>
#inclue <QString>

#include "table.h"

class Database {
 private:
  QString name;
  QString encoding;
  Table *tables;
}

#endif // DATABASE_H
