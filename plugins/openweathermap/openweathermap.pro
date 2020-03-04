include(openweathermap.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = openweathermap.h

SOURCES = openweathermap.cpp

TARGET = $$qtLibraryTarget(openweathermap)

DESTDIR = ../../plugins

EXAMPLE_FILES = openweathermap.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


