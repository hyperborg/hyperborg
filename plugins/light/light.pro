include(light.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = light.h

SOURCES = light.cpp

TARGET = $$qtLibraryTarget(light)

DESTDIR = ../../plugins

EXAMPLE_FILES = light.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


