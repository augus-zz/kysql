#include "query_model.h"

QueryModel::QueryModel(QSqlQuery *query, QObject *parent) : QAbstractTableModel(parent)
{
  this->query = query;
}

QueryModel::~QueryModel()
{
}

QVariant QueryModel::data(const QModelIndex &index, int role) const {
  if (!index.isValid())
    return QVariant();

  query->seek(index.row());
  return query->value(index.column());
}

int QueryModel::columnCount(const QModelIndex &parent) const {
  return query->record().count();
}

int QueryModel::rowCount(const QModelIndex &parent) const {
  return query->numRowsAffected();
}

QVariant QueryModel::headerData(int section, Qt::Orientation orientation, int role) const {
  if (role != Qt::DisplayRole)
    return QVariant();
  return query->record().value(section);
}

