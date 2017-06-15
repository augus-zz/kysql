#ifndef QUERY_MODEL_H

#include <QAbstractTableModel>

#include "../utils/logger.h"

class QueryModel : public QAbstractTableModel {
  Q_OBJECT

  public:
  explicit QueryModel(QObject *parent = Q_NULLPTR);
  ~QueryModel();
};

#endif // QUERY_MODEL_H
