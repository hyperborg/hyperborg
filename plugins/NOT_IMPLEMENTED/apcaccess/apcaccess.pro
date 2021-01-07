include(apcaccess.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = apcaccess.h

SOURCES = apcaccess.cpp

TARGET = $$qtLibraryTarget(apcaccess)

DESTDIR = ../../plugins

EXAMPLE_FILES = apcaccess.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


