include(opentherm_gw.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = opentherm_gw.h

SOURCES = opentherm_gw.cpp

TARGET = $$qtLibraryTarget(opentherm_gw)

DESTDIR = ../../plugins

EXAMPLE_FILES = opentherm_gw.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


