#include "application.h"

Application::Application(int &argc, char** argv):QApplication(argc, argv)
{
}

Application::~Application()
{
}

int Application::exec()
{
  MainWindow window;
  window.show();
  return QApplication::exec();
}
