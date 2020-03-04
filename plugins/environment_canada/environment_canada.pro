include(environment_canada.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = environment_canada.h

SOURCES = environment_canada.cpp

TARGET = $$qtLibraryTarget(environment_canada)

DESTDIR = ../../plugins

EXAMPLE_FILES = environment_canada.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


