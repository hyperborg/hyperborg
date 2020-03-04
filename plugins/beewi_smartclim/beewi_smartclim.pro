include(beewi_smartclim.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = beewi_smartclim.h

SOURCES = beewi_smartclim.cpp

TARGET = $$qtLibraryTarget(beewi_smartclim)

DESTDIR = ../../plugins

EXAMPLE_FILES = beewi_smartclim.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


