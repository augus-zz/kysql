#ifndef QUERY_MODEL_H

#include <QAbstractTableModel>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QVariant>
#include <QString>
#include <QObject>
#include <QModelIndex>

#include "../utils/logger.h"

class QueryModel : public QAbstractTableModel {
  Q_OBJECT

  public:
  explicit QueryModel(QSqlQuery *query, QObject *parent = Q_NULLPTR);
  ~QueryModel();

  public:
  QSqlQuery *query;

  public:
  QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
  int columnCount(const QModelIndex &parent = QModelIndex()) const;
  int rowCount(const QModelIndex &parent = QModelIndex()) const;
  QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

  // setData();
  // flags();
  // insertRows();
  // removeRows();
  // insertColumns();
  // removeColumns();
};

#endif // QUERY_MODEL_H
