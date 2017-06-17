#include "query_model.h"

QueryModel::QueryModel(QSqlQuery *query, QObject *parent) : QAbstractTableModel(parent)
{
  this->query = query;

  QSqlRecord record = query->record();
  for(int i = 0; i < record.count(); ++i)
  {
    Column column;
    column.name = record.fieldName(i);
    // logger(QString("column %1: %2").arg(i).arg(column.name).toStdString().c_str());
    columns.append(std::move(column));
  }
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

int QueryModel::columnCount(const QModelIndex &parent) const { return query->record().count(); }

int QueryModel::rowCount(const QModelIndex &parent) const
{
  return query->numRowsAffected();
}

QVariant QueryModel::headerData(int section, Qt::Orientation orientation, int role) const
{
  if(role != Qt::DisplayRole)
    return QVariant();
  if (orientation == Qt::Horizontal){
    return columns[section].name;
  }

  return QString("%1").arg(section);
}
