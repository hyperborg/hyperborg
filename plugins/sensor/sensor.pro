include(sensor.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = sensor.h

SOURCES = sensor.cpp

TARGET = $$qtLibraryTarget(sensor)

DESTDIR = ../../plugins

EXAMPLE_FILES = sensor.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


