include(melissa.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = melissa.h

SOURCES = melissa.cpp

TARGET = $$qtLibraryTarget(melissa)

DESTDIR = ../../plugins

EXAMPLE_FILES = melissa.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


