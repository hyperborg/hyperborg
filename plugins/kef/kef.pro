include(kef.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = kef.h

SOURCES = kef.cpp

TARGET = $$qtLibraryTarget(kef)

DESTDIR = ../../plugins

EXAMPLE_FILES = kef.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


