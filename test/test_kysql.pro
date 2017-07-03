QT += core gui sql testlib widgets

TEMPLATE = app
TARGET = test_main
INCLUDEPATH += .

PRO_PATH = $$PWD/..

include(../common.pro)

HEADERS += src/test_application.h \
src/utils/test_configuration.h \
src/utils/test_connection_manager.h

SOURCES += test_main.cpp\
src/test_application.cpp \
src/utils/test_configuration.cpp \
src/utils/test_connection_manager.cpp
