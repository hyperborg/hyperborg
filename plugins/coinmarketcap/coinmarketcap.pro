include(coinmarketcap.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = coinmarketcap.h

SOURCES = coinmarketcap.cpp

TARGET = $$qtLibraryTarget(coinmarketcap)

DESTDIR = ../../plugins

EXAMPLE_FILES = coinmarketcap.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


