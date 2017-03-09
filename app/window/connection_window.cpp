#include "connection_window.h"

ConnectionWindow::ConnectionWindow(QWidget *parent, Qt::WindowFlags f):QWidget(parent, f)
{
}

ConnectionWindow::~ConnectionWindow()
{
}

void ConnectionWindow::init_widget(Connection *connection)
{
  this->connection = connection;
  if(!this->connection->name.isNull())
  {
    set_connection_properties();
    return;
  }
  txt_connection_name = new QLineEdit;
  txt_connection_host = new QLineEdit;
  txt_connection_port = new QLineEdit;
  txt_connection_username = new QLineEdit;
  txt_connection_password = new QLineEdit;
  txt_connection_password->setEchoMode(QLineEdit::EchoMode::Password);

  QPushButton *btn_save = new QPushButton(tr("&Save"));
  QPushButton *btn_cancel = new QPushButton(tr("&Cancel"));

  QFormLayout *form_layout = new QFormLayout;
  form_layout->addRow(tr("&Name:"), txt_connection_name);
  form_layout->addRow(tr("&Host:"), txt_connection_host);
  form_layout->addRow(tr("&Port:"), txt_connection_port);
  form_layout->addRow(tr("&Username:"), txt_connection_username);
  form_layout->addRow(tr("&Password:"), txt_connection_password);

  QHBoxLayout *btn_layout = new QHBoxLayout;
  btn_layout->addWidget(btn_save);
  btn_layout->addWidget(btn_cancel);

  connect(btn_save, SIGNAL(clicked()), this, SLOT(save_connection()));
  connect(btn_cancel, SIGNAL(clicked()), parentWidget(), SLOT(close_page()));

  form_layout->addRow(btn_layout);
  form_layout->setSpacing(6);
  logger(std::to_string(form_layout->verticalSpacing()).c_str());
  setLayout(form_layout);
}

void ConnectionWindow::set_connection_properties()
{

}

void ConnectionWindow::save_connection()
{
  connection->name = txt_connection_name->text();
  connection->host = txt_connection_host->text();
  connection->port = txt_connection_port->text().toInt();
  connection->username = txt_connection_username->text();
  connection->password = txt_connection_password->text();

  logger("save_connection");
}
