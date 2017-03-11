#ifndef TABLE_H
#define TABLE_H

#include <QSqlTableModel>
#include <QSqlField>
#include <QString>

#include "column.h"

class Table
{
public:
  explicit Table();
  ~Table();

public:
  QString name;
  QList<Column *> columns;
};

#endif //TABLE_H
