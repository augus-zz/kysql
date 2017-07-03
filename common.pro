QMAKE_CXX = clang++
QMAKE_CXXFLAGS += -std=c++14

CONFIG += link_pkgconfig
CONFIG += c++14
PKGCONFIG += yaml-cpp gtest

DESTDIR = build/
OBJECTS_DIR = build/objects
MOC_DIR = build/mocs
DEFINES += QT_DEPRECATED_WARNINGS

HEADERS += $${PRO_PATH}/src/application.h \
$${PRO_PATH}/src/utils/logger.h \
$${PRO_PATH}/src/utils/path.h \
$${PRO_PATH}/src/utils/kstring.h \
$${PRO_PATH}/src/utils/configuration.h \
$${PRO_PATH}/src/models/connection.h \
$${PRO_PATH}/src/models/database.h \
$${PRO_PATH}/src/models/table.h \
$${PRO_PATH}/src/models/column.h \
$${PRO_PATH}/src/models/query_model.h \
$${PRO_PATH}/src/window/main_window.h \
$${PRO_PATH}/src/window/sql_editor.h \
$${PRO_PATH}/src/window/connection_window.h \
$${PRO_PATH}/src/window/db_viewer.h

SOURCES += $${PRO_PATH}/src/application.cpp \
$${PRO_PATH}/src/utils/configuration.cpp \
$${PRO_PATH}/src/models/connection.cpp \
$${PRO_PATH}/src/models/database.cpp \
$${PRO_PATH}/src/models/table.cpp \
$${PRO_PATH}/src/models/column.cpp \
$${PRO_PATH}/src/models/query_model.cpp \
$${PRO_PATH}/src/window/main_window.cpp \
$${PRO_PATH}/src/window/sql_editor.cpp \
$${PRO_PATH}/src/window/connection_window.cpp \
$${PRO_PATH}/src/window/db_viewer.cpp
