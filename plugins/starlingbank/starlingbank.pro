include(starlingbank.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = starlingbank.h

SOURCES = starlingbank.cpp

TARGET = $$qtLibraryTarget(starlingbank)

DESTDIR = ../../plugins

EXAMPLE_FILES = starlingbank.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


