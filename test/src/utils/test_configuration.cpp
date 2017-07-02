#include "test_configuration.h"

void TestConfiguration::initTestCase()
{
}

void TestConfiguration::cleanupTestCase()
{
}

Configuration* TestConfiguration::init_config()
{
  Configuration *config = Configuration::instance();
  config->config_path = FIXTRUES_PATH;
  config->config_filename = "config.yml";
}

void TestConfiguration::test_load()
{
  Configuration *config = init_config();
  QVERIFY(NULL != config);
  QVERIFY(true == config->load());
}

void TestConfiguration::test_not_exist()
{
 Configuration *config = init_config();
 QCOMPARE(0, config->get_int("test_int_1", 0));
}

void TestConfiguration::test_get_int()
{
 Configuration *config = init_config();
 QCOMPARE(1, config->get_int("test_int"));
}

void TestConfiguration::test_get_string()
{
 Configuration *config = init_config();
 QCOMPARE("test", kstr(config->get_string("test_string")));
}

void TestConfiguration::test_save()
{

}
