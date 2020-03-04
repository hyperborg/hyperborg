include(yweather.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = yweather.h

SOURCES = yweather.cpp

TARGET = $$qtLibraryTarget(yweather)

DESTDIR = ../../plugins

EXAMPLE_FILES = yweather.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


