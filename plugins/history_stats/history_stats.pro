include(history_stats.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = history_stats.h

SOURCES = history_stats.cpp

TARGET = $$qtLibraryTarget(history_stats)

DESTDIR = ../../plugins

EXAMPLE_FILES = history_stats.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


