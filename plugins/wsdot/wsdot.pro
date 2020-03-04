include(wsdot.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = wsdot.h

SOURCES = wsdot.cpp

TARGET = $$qtLibraryTarget(wsdot)

DESTDIR = ../../plugins

EXAMPLE_FILES = wsdot.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


