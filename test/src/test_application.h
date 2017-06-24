#ifndef TEST_APPLICATION_H
#define TEST_APPLICATION_H

#include <QtTest/QtTest>

#include "../src/application.h"

class TestApplication: public QObject
{
    Q_OBJECT
private slots:
  void create_application();
};

#endif // TEST_APPLICATION_H
