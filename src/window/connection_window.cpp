#include "connection_window.h"

ConnectionWindow::ConnectionWindow(Connection *connection, QWidget *parent, Qt::WindowFlags f):QWidget(parent, f)
{
  this->connection = connection;
  init();
}

ConnectionWindow::~ConnectionWindow()
{
}

void ConnectionWindow::init()
{
  if(this->connection && !this->connection->name.isNull())
  {
    set_connection_properties();
    return;
  }
  txt_connection_name = new QLineEdit;
  txt_connection_host = new QLineEdit;
  txt_connection_port = new QLineEdit;
  txt_connection_username = new QLineEdit;
  txt_connection_password = new QLineEdit;

  txt_connection_name->setPlaceholderText(QString("New Connection"));
  txt_connection_host->setPlaceholderText(QString("localost"));
  txt_connection_port->setPlaceholderText(QString("3306"));
  txt_connection_username->setPlaceholderText(QString("root"));
  txt_connection_password->setEchoMode(QLineEdit::EchoMode::Password);

  txt_connection_name->setFocusPolicy(Qt::StrongFocus);

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

  connect(btn_save, SIGNAL(clicked()), parentWidget(), SLOT(save_connection()));
  connect(btn_cancel, SIGNAL(clicked()), parentWidget(), SLOT(close_tab_page()));

  form_layout->addRow(btn_layout);
  form_layout->setSpacing(6);
  setLayout(form_layout);
}

void ConnectionWindow::set_connection_properties()
{
}
