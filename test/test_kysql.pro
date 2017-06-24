QT += core gui sql testlib widgets

TEMPLATE = app
TARGET = test_main
INCLUDEPATH += .

QMAKE_CXX = clang++
QMAKE_CXXFLAGS += -std=c++14

DESTDIR = build/
OBJECTS_DIR = build/objects
MOC_DIR = build/mocs

DEFINES += QT_DEPRECATED_WARNINGS

INCLUDEPATH += /usr/local/include
LIBS += -L"/usr/local/lib" -lyaml-cpp

HEADERS += ../src/application.h \
../src/utils/logger.h \
../src/models/connection.h \
../src/models/database.h \
../src/models/table.h \
../src/models/column.h \
../src/models/query_model.h \
../src/window/main_window.h \
../src/window/sql_editor.h \
../src/window/connection_window.h \
../src/window/db_viewer.h

SOURCES += ../src/application.cpp \
../src/models/connection.cpp \
../src/models/database.cpp \
../src/models/table.cpp \
../src/models/column.cpp \
../src/models/query_model.cpp \
../src/window/main_window.cpp \
../src/window/sql_editor.cpp \
../src/window/connection_window.cpp \
../src/window/db_viewer.cpp

HEADERS += src/test_application.h \
src/utils/test_configuration.h

SOURCES += test_main.cpp\
src/test_application.cpp \
src/utils/test_configuration.cpp
