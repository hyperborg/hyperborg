include(config.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = config.h

SOURCES = config.cpp

TARGET = $$qtLibraryTarget(config)

DESTDIR = ../../plugins

EXAMPLE_FILES = config.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


