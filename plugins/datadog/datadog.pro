include(datadog.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = datadog.h

SOURCES = datadog.cpp

TARGET = $$qtLibraryTarget(datadog)

DESTDIR = ../../plugins

EXAMPLE_FILES = datadog.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


