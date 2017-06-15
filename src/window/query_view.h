#ifndef QUERY_VIEW_H
#define QUERY_VIEW_H

#include <QTableView>

#include "./utils/logger.h"

class QueryView : public QTableView {
  Q_OBJECT

  public:
    explicit QueryView(QWidget *parent = Q_NULLPTR);
    ~QueryView();
};

#endif // QUERY_VIEW_H
