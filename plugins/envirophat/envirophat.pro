include(envirophat.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = envirophat.h

SOURCES = envirophat.cpp

TARGET = $$qtLibraryTarget(envirophat)

DESTDIR = ../../plugins

EXAMPLE_FILES = envirophat.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


