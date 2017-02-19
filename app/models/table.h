#ifndef TABLE_H
#define TABLE_H

#include <QSqlTableModel>
#include <QSqlField>
#include <QString>

class Table {

 private:
 QString name,
 QList<Field> field_list;
}

#endif TABLE_H
