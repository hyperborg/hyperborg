include(aprs.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = aprs.h

SOURCES = aprs.cpp

TARGET = $$qtLibraryTarget(aprs)

DESTDIR = ../../plugins

EXAMPLE_FILES = aprs.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


