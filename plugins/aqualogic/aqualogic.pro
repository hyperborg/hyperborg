include(aqualogic.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = aqualogic.h

SOURCES = aqualogic.cpp

TARGET = $$qtLibraryTarget(aqualogic)

DESTDIR = ../../plugins

EXAMPLE_FILES = aqualogic.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


