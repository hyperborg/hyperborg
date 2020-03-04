include(vultr.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = vultr.h

SOURCES = vultr.cpp

TARGET = $$qtLibraryTarget(vultr)

DESTDIR = ../../plugins

EXAMPLE_FILES = vultr.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


