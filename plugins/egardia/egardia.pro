include(egardia.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = egardia.h

SOURCES = egardia.cpp

TARGET = $$qtLibraryTarget(egardia)

DESTDIR = ../../plugins

EXAMPLE_FILES = egardia.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


