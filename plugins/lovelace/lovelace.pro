include(lovelace.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = lovelace.h

SOURCES = lovelace.cpp

TARGET = $$qtLibraryTarget(lovelace)

DESTDIR = ../../plugins

EXAMPLE_FILES = lovelace.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


