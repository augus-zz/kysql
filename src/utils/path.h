#ifndef PATH_H
#define PATH_H

#include <QDir>

static QString _path_join(const QString& v) {
    return v;
}

template<typename... Args>
QString path_join(const QString& first, Args... args) {
    return QDir(first).filePath(_path_join(args...));
}

#endif
