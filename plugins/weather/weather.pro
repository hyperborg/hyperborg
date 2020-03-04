include(weather.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = weather.h

SOURCES = weather.cpp

TARGET = $$qtLibraryTarget(weather)

DESTDIR = ../../plugins

EXAMPLE_FILES = weather.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


