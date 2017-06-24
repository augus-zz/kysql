#include "test_application.h"

void TestApplication::create_application()
{
  char *argv[] = {"kysql", "arg1"};
  Application *app = new Application(2, argv);
  QTimer::singleShot(3000, &(app->main_window), SLOT(close()));
  app->exec();
}
