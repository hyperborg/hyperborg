include(supla.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = supla.h

SOURCES = supla.cpp

TARGET = $$qtLibraryTarget(supla)

DESTDIR = ../../plugins

EXAMPLE_FILES = supla.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


