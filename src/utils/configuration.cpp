#include "configuration.h"

Configuration* Configuration::inst = NULL;

Configuration* Configuration::instance()
{
  if (!inst)
    inst = new Configuration();

  return inst;
}

Configuration::~Configuration()
{
}

bool Configuration::save()
{
  return true;
}

bool Configuration::load()
{
  logger(path_join(config_path, config_filename).toStdString().c_str());
  config = YAML::LoadFile(path_join(config_path, config_filename).toStdString().c_str());
  return true;
}

QString Configuration::get_string(QString key, QString v)
{
  return v;
}

int Configuration::get_int(QString key, int v)
{
  return v;
}

double Configuration::get_double(QString key, double v)
{
  return v;
}

QDate Configuration::get_date(QString key, QDate v)
{
  return v;
}

QTime Configuration::get_time(QString key, QTime v)
{
  return v;
}

QDateTime Configuration::get_datetime(QString key, QDateTime v)
{
  return v;
}
