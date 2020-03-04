include(nanoleaf.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = nanoleaf.h

SOURCES = nanoleaf.cpp

TARGET = $$qtLibraryTarget(nanoleaf)

DESTDIR = ../../plugins

EXAMPLE_FILES = nanoleaf.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


