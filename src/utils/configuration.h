#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QDate>
#include <QTime>
#include <QDateTime>
#include <yaml-cpp/yaml.h>
#include "logger.h"
#include "path.h"

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

  QString get_string(QString key, QString v = "");
  int get_int(QString key, int v = 0);
  double get_double(QString key, double v = 0.0);
  QDate get_date(QString key, QDate v = QDate::currentDate());
  QTime get_time(QString key, QTime v = QTime::currentTime());
  QDateTime get_datetime(QString key, QDateTime v = QDateTime::currentDateTime());

protected:
  Configuration(){}

private:
  static Configuration *inst;

private:
  YAML::Node config;
};

#endif // CONFIGURATION_H
