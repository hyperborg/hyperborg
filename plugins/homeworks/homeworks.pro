include(homeworks.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = homeworks.h

SOURCES = homeworks.cpp

TARGET = $$qtLibraryTarget(homeworks)

DESTDIR = ../../plugins

EXAMPLE_FILES = homeworks.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


