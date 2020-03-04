include(bme680.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = bme680.h

SOURCES = bme680.cpp

TARGET = $$qtLibraryTarget(bme680)

DESTDIR = ../../plugins

EXAMPLE_FILES = bme680.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


