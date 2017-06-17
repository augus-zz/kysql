#include "query_model.h"

QueryModel::QueryModel(QSqlQuery *query, QObject *parent) : QAbstractTableModel(parent)
{
  this->query = query;
}

QueryModel::~QueryModel()
{
}

QVariant QueryModel::data(const QModelIndex &index, int role) const
{
  if (!index.isValid())
    return QVariant();

  query->seek(index.row());
  return query->value(index.column());
}

int QueryModel::columnCount(const QModelIndex &parent) const
{
  return query->record().count();
}

int QueryModel::rowCount(const QModelIndex &parent) const
{
  return query->numRowsAffected();
}

QVariant QueryModel::headerData(int section, Qt::Orientation orientation, int role) const
{
  if (role != Qt::DisplayRole)
    return QVariant();
  // logger(QString("column %1").arg(section).toStdString().c_str());
  return query->record().value(section);
}

QList<Column *> QueryModel::columns() const
{
  QList<Column *> columns;
  QSqlRecord record = query->record();
  for(int i = 0; i < record.count(); ++i)
  {
    Column *column = new Column;
    column->name = record.fieldName(i);
    column->type = record.value(i).type();

    // logger(QString("column %1: %2").arg(i).arg(column->name).toStdString().c_str());
    columns.append(column);
  }
  return columns;
}

