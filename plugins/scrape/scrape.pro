include(scrape.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = scrape.h

SOURCES = scrape.cpp

TARGET = $$qtLibraryTarget(scrape)

DESTDIR = ../../plugins

EXAMPLE_FILES = scrape.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


