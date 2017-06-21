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
  char *argv[] = {"kysql", "arg1", NULL};
  Application *app = new Application(1, argv);
  app->exec();
}

QTEST_MAIN(TestApplication)
#include "build/mocs/test_application.moc"
