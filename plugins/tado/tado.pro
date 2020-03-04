include(tado.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = tado.h

SOURCES = tado.cpp

TARGET = $$qtLibraryTarget(tado)

DESTDIR = ../../plugins

EXAMPLE_FILES = tado.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


