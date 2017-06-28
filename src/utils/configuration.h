#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <yaml-cpp/yaml.h>

class Configuration
{
public:
  static Configuration* instance();
  ~Configuration();

public:
  bool save();
  bool load();
  QVariant get(QString key, QVariant default_value = QVariant::Invalid);

protected:
  Configuration(){}

private:
  Configuration *inst = NULL;
};

#endif // CONFIGURATION_H
