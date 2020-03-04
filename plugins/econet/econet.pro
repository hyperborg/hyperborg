include(econet.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = econet.h

SOURCES = econet.cpp

TARGET = $$qtLibraryTarget(econet)

DESTDIR = ../../plugins

EXAMPLE_FILES = econet.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


