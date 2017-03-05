#ifndef CONNECTION_WINDOW_H
#define CONNECTION_WINDOW_H

#include <QDialog>
#include <QTextEdit>
#include <QPushButton>
#include <QFormLayout>
#include <QHBoxLayout>

#include "../models/connection.h"

class ConnectionWindow : public QDialog {
  Q_OBJECT

 public:
  explicit ConnectionWindow(QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
  ~ConnectionWindow();

 public:
  void init_dialog();
  void show_dialog(Connection *connection);
  void set_connection_properties();

 public:
  Connection *connection;

 private:
 QTextEdit *txt_connection_name;
 QTextEdit *txt_connection_host;
 QTextEdit *txt_connection_port;
 QTextEdit *txt_connection_username;
 QTextEdit *txt_connection_password;
};

#endif // CONNECTION_WINDOW_H
