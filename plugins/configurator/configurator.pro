include(configurator.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = configurator.h

SOURCES = configurator.cpp

TARGET = $$qtLibraryTarget(configurator)

DESTDIR = ../../plugins

EXAMPLE_FILES = configurator.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


