TEMPLATE = app
TARGET = kysql
INCLUDEPATH += .

QT       += core gui network sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += debug release

DESTDIR = build/
OBJECTS_DIR = build/objects
MOC_DIR = build/mocs

QMAKE_CXX = clang++
QMAKE_CXXFLAGS += -std=c++14

DEFINES += QT_MESSAGELOGCONTEXT

INCLUDEPATH += /usr/local/include/
LIBS += -L"/usr/local/lib" -lyaml-cpp

# Input
HEADERS += src/application.h \
src/utils/logger.h \
src/models/connection.h \
src/models/database.h \
src/models/table.h \
src/models/column.h \
src/models/query_model.h \
src/window/main_window.h \
src/window/sql_editor.h \
src/window/connection_window.h \
src/window/db_viewer.h

SOURCES += main.cpp src/application.cpp \
src/models/connection.cpp \
src/models/database.cpp \
src/models/table.cpp \
src/models/column.cpp \
src/models/query_model.cpp \
src/window/main_window.cpp \
src/window/sql_editor.cpp \
src/window/connection_window.cpp \
src/window/db_viewer.cpp
