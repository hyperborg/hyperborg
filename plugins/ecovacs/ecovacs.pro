include(ecovacs.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = ecovacs.h

SOURCES = ecovacs.cpp

TARGET = $$qtLibraryTarget(ecovacs)

DESTDIR = ../../plugins

EXAMPLE_FILES = ecovacs.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


