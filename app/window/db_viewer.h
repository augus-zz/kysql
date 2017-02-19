#ifndef DB_VIEWER_H
#define DB_VIEWER_H

#include <QtCore>
#include <QtGui>

#include <QTreeView>

class DbViewer: public QTreeView {
  Q_OBJECT

 public:
  explicit DbViewer(QWidget *parent = 0);
  ~DbViewer();

 protected:

 private:
}

#endif // DB_VIEWER_H
