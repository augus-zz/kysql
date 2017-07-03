TEMPLATE = app
TARGET = kysql
INCLUDEPATH += .

QT       += core gui network sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += release

PRO_PATH = $$PWD

include(common.pro)

SOURCES += main.cpp
