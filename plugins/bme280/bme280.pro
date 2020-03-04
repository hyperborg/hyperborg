include(bme280.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = bme280.h

SOURCES = bme280.cpp

TARGET = $$qtLibraryTarget(bme280)

DESTDIR = ../../plugins

EXAMPLE_FILES = bme280.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


