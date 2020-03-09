include(sqlplugin.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml sql

INCLUDEPATH +=../../common

HEADER = sqlplugin.h

SOURCES = sqlplugin.cpp

TARGET = $$qtLibraryTarget(sqlplugin)

DESTDIR = ../../plugins

EXAMPLE_FILES = sqlplugin.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


