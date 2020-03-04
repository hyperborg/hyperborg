include(system_log.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = system_log.h

SOURCES = system_log.cpp

TARGET = $$qtLibraryTarget(system_log)

DESTDIR = ../../plugins

EXAMPLE_FILES = system_log.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


