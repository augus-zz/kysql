#include "connection_window.h"

ConnectionWindow::ConnectionWindow(QWidget *parent, Qt::WindowFlags f):QDialog(parent, f)
{
  init_dialog();
}

ConnectionWindow::~ConnectionWindow()
{
}

void ConnectionWindow::show_dialog(Connection *connection)
{
  this->connection = connection;

  if(this->connection->name.isNull())
  {
    set_connection_properties();
  }

  // show();
  // raise();
  // activateWindow();
  exec();
}

void ConnectionWindow::init_dialog()
{
  txt_connection_name = new QTextEdit;
  txt_connection_host = new QTextEdit;
  txt_connection_port = new QTextEdit;
  txt_connection_username = new QTextEdit;
  txt_connection_password = new QTextEdit;

  QPushButton *btn_save = new QPushButton(tr("&Save"));
  QPushButton *btn_cancel = new QPushButton(tr("&Cancel"));

  QFormLayout *formLayout = new QFormLayout;
  formLayout->addRow(tr("&Name:"), txt_connection_name);
  formLayout->addRow(tr("&Host:"), txt_connection_host);
  formLayout->addRow(tr("&Port:"), txt_connection_port);
  formLayout->addRow(tr("&Username:"), txt_connection_username);
  formLayout->addRow(tr("&Password:"), txt_connection_password);

  QHBoxLayout *btn_layout = new QHBoxLayout;
  btn_layout->addWidget(btn_save);
  btn_layout->addWidget(btn_cancel);

  formLayout->addRow(btn_layout);
  setLayout(formLayout);
}

void ConnectionWindow::set_connection_properties()
{

}
