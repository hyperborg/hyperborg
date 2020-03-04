include(volvooncall.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = volvooncall.h

SOURCES = volvooncall.cpp

TARGET = $$qtLibraryTarget(volvooncall)

DESTDIR = ../../plugins

EXAMPLE_FILES = volvooncall.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


