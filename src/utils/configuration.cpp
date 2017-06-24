#include "configuration.h"

static Configuration* Configuration::instance()
{
  if (!inst)
    inst = new Configuration();
  return inst;
}
