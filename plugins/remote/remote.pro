include(remote.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = remote.h

SOURCES = remote.cpp

TARGET = $$qtLibraryTarget(remote)

DESTDIR = ../../plugins

EXAMPLE_FILES = remote.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


