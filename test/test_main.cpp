#include <QtTest>
#include <QApplication>

#include "test_helper.h"

int main(int argc, char** argv)
{
  QApplication app(argc, argv);

  TestApplication test_application;
  TestConfiguration test_configuration;
  {
    QTest::qExec(&test_configuration, argc, argv);
    QTest::qExec(&test_application, argc, argv);
  }
}
