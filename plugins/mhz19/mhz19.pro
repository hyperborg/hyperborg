include(mhz19.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = mhz19.h

SOURCES = mhz19.cpp

TARGET = $$qtLibraryTarget(mhz19)

DESTDIR = ../../plugins

EXAMPLE_FILES = mhz19.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


