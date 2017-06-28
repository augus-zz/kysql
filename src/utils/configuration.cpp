#include "configuration.h"

static Configuration* Configuration::instance()
{
  if (!inst)
    inst = new Configuration();
  return inst;
}

Configuration::~Configuration()
{
  if(inst)
    delete inst;
}

bool Configuration::save()
{
  return true;
}

bool Configuration::load()
{
  return true;
}

QVariant Configuration::get(QString key, QVariant default_value)
{
  return default_value;
}
