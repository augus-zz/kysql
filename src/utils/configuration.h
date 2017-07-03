#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QDate>
#include <QTime>
#include <QDateTime>
#include <iostream>
#include <fstream>

#include <yaml-cpp/yaml.h>
#include "logger.h"
#include "path.h"
#include "kstring.h"

using namespace std;

class Configuration
{
public:
  static Configuration* instance();
  ~Configuration();

public:
  QString config_path;
  QString config_filename;

public:
  QList<QString> search_config();
  bool save();
  bool load();
  bool is_exist(QString key);

  QString get_string(QString key, QString v = "");
  int get_int(QString key, int v = 0);
  double get_double(QString key, double v = 0.0);
  QDate get_date(QString key, QDate v = QDate::currentDate());
  QTime get_time(QString key, QTime v = QTime::currentTime());
  QDateTime get_datetime(QString key, QDateTime v = QDateTime::currentDateTime());
  QList<int> get_int_list(QString key, QList<int> v = QList<int>());
  QList<QString> get_string_list(QString key, QList<QString> v = QList<QString>());

protected:
  Configuration(){}

public:
  static Configuration *inst;
  YAML::Node config;

public:
  QStringList split_key(QString key);
  bool key_exist(YAML::Node node, QStringList keys);
  YAML::Node key_get(YAML::Node node, QStringList keys);
};

#endif // CONFIGURATION_H
