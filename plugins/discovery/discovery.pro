include(discovery.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = discovery.h

SOURCES = discovery.cpp

TARGET = $$qtLibraryTarget(discovery)

DESTDIR = ../../plugins

EXAMPLE_FILES = discovery.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


