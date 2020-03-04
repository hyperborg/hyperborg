include(hangouts.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = hangouts.h

SOURCES = hangouts.cpp

TARGET = $$qtLibraryTarget(hangouts)

DESTDIR = ../../plugins

EXAMPLE_FILES = hangouts.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


