#include "test_configuration.h"

void TestConfiguration::initTestCase()
{

}

void TestConfiguration::cleanupTestCase()
{

}

void TestConfiguration::test_load()
{
  Configuration *config = Configuration::instance();
  config->config_path = FIXTRUES_PATH;
  config->config_filename = "config.yml";

  QVERIFY(true == config->load());

  delete config;
}

void TestConfiguration::test_save()
{

}
