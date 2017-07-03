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
  std::ofstream out(kstr(path_join(config_path, config_filename)));
  out << config;
  return true;
}

bool Configuration::load()
{
  // logger(kstr(path_join(config_path, config_filename)));
  config = YAML::LoadFile(kstr(path_join(config_path, config_filename)));
  return true;
}

QStringList Configuration::split_key(QString key)
{
  return key.split(".", QString::SkipEmptyParts);
}

bool Configuration::is_exist(QString key)
{
  return key_exist(config, split_key(key));
}

bool Configuration::key_exist(YAML::Node node, QStringList keys)
{
  return !key_get(node, keys).IsNull();
}

YAML::Node Configuration::key_get(YAML::Node node, QStringList keys)
{
  // logger(kstr(keys.join(",")));
  static YAML::Node _node;
  if(node.IsNull() || !node.IsMap() || keys.empty())
    return _node;

  auto size = keys.size();
  if(size == 1)
    if(node[kstr(keys.at(0))].IsNull())
      return _node;
    else
      return node[kstr(keys.at(0))];

  if(size > 1)
  {
    auto parent_key = keys.takeFirst();
    return key_get(node[kstr(parent_key)], keys);
  }
}

QString Configuration::get_string(QString key, QString v)
{
  YAML::Node node = key_get(config, split_key(key));
  if(node.IsNull())
    return v;
  return QString::fromStdString(node.as<std::string>());
}

int Configuration::get_int(QString key, int v)
{
  YAML::Node node = key_get(config, split_key(key));
  if(node.IsNull())
    return v;
  return node.as<int>();
}

double Configuration::get_double(QString key, double v)
{
  YAML::Node node = key_get(config, split_key(key));
  if(node.IsNull())
    return v;
  return node.as<double>();
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

QList<int> Configuration::get_int_list(QString key, QList<int> v)
{
  return v;
}

QList<QString> Configuration::get_string_list(QString key, QList<QString> v)
{
  return v;
}
