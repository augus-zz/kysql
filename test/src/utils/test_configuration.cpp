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

  return config;
}

void TestConfiguration::test_load()
{
  Configuration *config = init_config();
  QVERIFY(NULL != config);
  QVERIFY(true == config->load());
}

void TestConfiguration::test_save()
{

}

void TestConfiguration::test_split_key()
{
  Configuration *config = init_config();
  QString str1 = "a.b.c";
  QStringList ret1 = config->split_key(str1);
  QCOMPARE(3, ret1.size());

  QString str2 = "c";
  QStringList ret2 = config->split_key(str2);
  QCOMPARE(1, ret2.size());

  QString str3 = "";
  QStringList ret3 = config->split_key(str3);
  QCOMPARE(0, ret3.size());
}

void TestConfiguration::test_is_exist()
{
  Configuration *config = init_config();
  config->load();

  // cout << config->config;
  QCOMPARE(false, config->is_exist("test_not_exist"));
  QCOMPARE(false, config->is_exist("test.int"));
  QCOMPARE(true, config->is_exist("test_int"));
  QCOMPARE(true, config->is_exist("test_nested.test_int"));
}

void TestConfiguration::test_key_exist()
{

}

void TestConfiguration::test_key_get()
{
}

void TestConfiguration::test_get_int()
{
  Configuration *config = init_config();
  config->load();
  QCOMPARE(1, config->get_int("test_int"));
  QCOMPARE(0, config->get_int("test_int_not_exist"));
  QCOMPARE(10, config->get_int("test_int_not_exist", 10));
}

void TestConfiguration::test_get_string()
{
  Configuration *config = init_config();
  config->load();
  QCOMPARE(QString("test"), config->get_string("test_string"));
  QCOMPARE(QString(""), config->get_string("test_string_not_exist"));
  QCOMPARE(QString("default"), config->get_string("test_string_not_exist", "default"));
  QCOMPARE(QString("test"), config->get_string("test_tested.test_string"));
}
