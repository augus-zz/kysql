#ifndef CONFIGURATION_H
#define CONFIGURATION_H

class Configuration
{
public:
  static Configuration* instance();

public:
  bool save();
  bool load();
  QVariant get(QString key);

protected:
    Configuration(){}

private:
    Configuration *inst = NULL;
};

#endif // CONFIGURATION_H
