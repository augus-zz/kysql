#include "include_helper.h"

#define ADD_TEST(cls) { cls instance; QTest::qExec(&instance, argc, argv); }

#define INCLUDE_ALL_TESTS(argc, argv) {   \
    ADD_TEST(TestConfiguration);  \
    ADD_TEST(TestApplication);    \
}
