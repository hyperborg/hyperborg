include(lifx_legacy.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = lifx_legacy.h

SOURCES = lifx_legacy.cpp

TARGET = $$qtLibraryTarget(lifx_legacy)

DESTDIR = ../../plugins

EXAMPLE_FILES = lifx_legacy.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


