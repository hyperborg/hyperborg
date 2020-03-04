include(currencylayer.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = currencylayer.h

SOURCES = currencylayer.cpp

TARGET = $$qtLibraryTarget(currencylayer)

DESTDIR = ../../plugins

EXAMPLE_FILES = currencylayer.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


