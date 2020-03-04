include(logger.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = logger.h

SOURCES = logger.cpp

TARGET = $$qtLibraryTarget(logger)

DESTDIR = ../../plugins

EXAMPLE_FILES = logger.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


