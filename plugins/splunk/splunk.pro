include(splunk.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = splunk.h

SOURCES = splunk.cpp

TARGET = $$qtLibraryTarget(splunk)

DESTDIR = ../../plugins

EXAMPLE_FILES = splunk.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


