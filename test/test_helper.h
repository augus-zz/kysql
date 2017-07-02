#include "include_helper.h"

#ifndef TEST_HELPER_H
#define TEST_HELPER_H

#include <QDir>

#define ADD_TEST(cls) { cls instance; QTest::qExec(&instance, argc, argv); }

#define INCLUDE_ALL_TESTS(argc, argv) {   \
    ADD_TEST(TestConfiguration);  \
    ADD_TEST(TestApplication);    \
}

const QString CUR_PATH = QDir(QString(__FILE__) + QString("/..")).absolutePath();
const QString FIXTRUES_PATH = CUR_PATH + "/fixtures";

#endif
