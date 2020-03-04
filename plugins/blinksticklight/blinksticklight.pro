include(blinksticklight.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = blinksticklight.h

SOURCES = blinksticklight.cpp

TARGET = $$qtLibraryTarget(blinksticklight)

DESTDIR = ../../plugins

EXAMPLE_FILES = blinksticklight.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


