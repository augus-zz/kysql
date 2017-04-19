#ifndef COLUMN_H
#define COLUMN_H

#include <QString>
#include <QVariant>

class Column
{
public:
  explicit Column();
  ~Column();

public:
  QString name;
  QVariant::Type type;
  QVariant default_value;
  bool is_null;
  bool is_auto_value;
  bool is_required;
  int length;
  int precise;
};

#endif // COLUMN_H
