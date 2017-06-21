#include "application.h"

Application::Application(int argc, char** argv) : QApplication(argc, argv)
{
}

Application::~Application()
{
  for(auto &connection : connections)
  {
    if(connection)
    {
      logger("ready to close connection");
      if(connection->open())
      {
        connection->close();
      }
      delete connection;
    }
  }
 }

int Application::exec()
{
  main_window.show();
  return QApplication::exec();
}
