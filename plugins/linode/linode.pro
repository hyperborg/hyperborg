include(linode.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = linode.h

SOURCES = linode.cpp

TARGET = $$qtLibraryTarget(linode)

DESTDIR = ../../plugins

EXAMPLE_FILES = linode.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


