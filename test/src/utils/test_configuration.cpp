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

  logger(config->config_path.toStdString().c_str());
  logger(config->config_filename.toStdString().c_str());
  QVERIFY(true == config->load());

  delete config;
}

void TestConfiguration::test_save()
{

}
