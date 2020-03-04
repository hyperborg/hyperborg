include(keenetic_ndms2.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = keenetic_ndms2.h

SOURCES = keenetic_ndms2.cpp

TARGET = $$qtLibraryTarget(keenetic_ndms2)

DESTDIR = ../../plugins

EXAMPLE_FILES = keenetic_ndms2.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


