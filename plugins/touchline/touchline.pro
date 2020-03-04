include(touchline.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = touchline.h

SOURCES = touchline.cpp

TARGET = $$qtLibraryTarget(touchline)

DESTDIR = ../../plugins

EXAMPLE_FILES = touchline.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


