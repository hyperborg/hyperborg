include(spotcrime.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = spotcrime.h

SOURCES = spotcrime.cpp

TARGET = $$qtLibraryTarget(spotcrime)

DESTDIR = ../../plugins

EXAMPLE_FILES = spotcrime.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


