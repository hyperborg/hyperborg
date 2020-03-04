include(trafikverket_train.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = trafikverket_train.h

SOURCES = trafikverket_train.cpp

TARGET = $$qtLibraryTarget(trafikverket_train)

DESTDIR = ../../plugins

EXAMPLE_FILES = trafikverket_train.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


