include(lupusec.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = lupusec.h

SOURCES = lupusec.cpp

TARGET = $$qtLibraryTarget(lupusec)

DESTDIR = ../../plugins

EXAMPLE_FILES = lupusec.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


