include(frontier_silicon.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = frontier_silicon.h

SOURCES = frontier_silicon.cpp

TARGET = $$qtLibraryTarget(frontier_silicon)

DESTDIR = ../../plugins

EXAMPLE_FILES = frontier_silicon.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


