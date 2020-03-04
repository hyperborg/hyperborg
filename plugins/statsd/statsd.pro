include(statsd.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = statsd.h

SOURCES = statsd.cpp

TARGET = $$qtLibraryTarget(statsd)

DESTDIR = ../../plugins

EXAMPLE_FILES = statsd.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


