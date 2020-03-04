include(opensky.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = opensky.h

SOURCES = opensky.cpp

TARGET = $$qtLibraryTarget(opensky)

DESTDIR = ../../plugins

EXAMPLE_FILES = opensky.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


