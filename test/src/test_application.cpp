#include <QtTest/QtTest>

class TestApplication: public QObject
{
    Q_OBJECT
private slots:
};


QTEST_MAIN(TestApplication)
#include "build/mocs/test_application.moc"
