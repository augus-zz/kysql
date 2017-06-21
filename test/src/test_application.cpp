#include <QtTest/QtTest>

#include "../src/application.h"

class TestApplication: public QObject
{
    Q_OBJECT
private slots:
  void create_application();
};

void TestApplication::create_application()
{
  char *argv[] = {"kysql", "arg1"};
  Application *app = new Application(2, argv);
  QTimer::singleShot(3000, &(app->main_window), SLOT(close()));
  app->exec();
}

QTEST_MAIN(TestApplication)
#include "build/mocs/test_application.moc"
