#ifndef TEST_CONFIGURATION_H
#define TEST_CONFIGURATION_H

#include <QtTest/QtTest>

#include "../src/utils/configuration.h"

class TestConfiguration: public QObject
{
  Q_OBJECT
private slots:
  void initTestCase();
  void cleanupTestCase();

private slots:
  void create_configuration();
};

#endif // TEST_CONFIGURATION_H
