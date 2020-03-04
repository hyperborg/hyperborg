include(solarlog.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = solarlog.h

SOURCES = solarlog.cpp

TARGET = $$qtLibraryTarget(solarlog)

DESTDIR = ../../plugins

EXAMPLE_FILES = solarlog.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


