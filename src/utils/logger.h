#ifndef LOGGER_H
#define LOGGER_H

#include <QMessageLogger>

#define logger(msg) \
  QMessageLogger(__FILE__, __LINE__, Q_FUNC_INFO).debug(msg)

#define qlogger(msg) \
  QMessageLogger(__FILE__, __LINE__, Q_FUNC_INFO).debug(msg.toStdString().c_str())
#endif // LOGGER_H
