include(amazon_polly.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = amazon_polly.h

SOURCES = amazon_polly.cpp

TARGET = $$qtLibraryTarget(amazon_polly)

DESTDIR = ../../plugins

EXAMPLE_FILES = amazon_polly.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


