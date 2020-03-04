include(version.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = version.h

SOURCES = version.cpp

TARGET = $$qtLibraryTarget(version)

DESTDIR = ../../plugins

EXAMPLE_FILES = version.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


