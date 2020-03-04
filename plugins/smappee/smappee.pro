include(smappee.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = smappee.h

SOURCES = smappee.cpp

TARGET = $$qtLibraryTarget(smappee)

DESTDIR = ../../plugins

EXAMPLE_FILES = smappee.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


