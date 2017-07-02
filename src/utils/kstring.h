#ifndef KSTRING_H
#define KSTRING_H

#include <QString>

#define kstr(str) \
  str.toStdString().c_str()

#endif // KSTRING_H
