include(kira.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = kira.h

SOURCES = kira.cpp

TARGET = $$qtLibraryTarget(kira)

DESTDIR = ../../plugins

EXAMPLE_FILES = kira.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


