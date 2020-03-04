include(alert.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = alert.h

SOURCES = alert.cpp

TARGET = $$qtLibraryTarget(alert)

DESTDIR = ../../plugins

EXAMPLE_FILES = alert.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


