include(oasa_telematics.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = oasa_telematics.h

SOURCES = oasa_telematics.cpp

TARGET = $$qtLibraryTarget(oasa_telematics)

DESTDIR = ../../plugins

EXAMPLE_FILES = oasa_telematics.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


