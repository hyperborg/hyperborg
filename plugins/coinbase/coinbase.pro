include(coinbase.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = coinbase.h

SOURCES = coinbase.cpp

TARGET = $$qtLibraryTarget(coinbase)

DESTDIR = ../../plugins

EXAMPLE_FILES = coinbase.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


