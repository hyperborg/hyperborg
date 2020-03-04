include(fritzbox.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = fritzbox.h

SOURCES = fritzbox.cpp

TARGET = $$qtLibraryTarget(fritzbox)

DESTDIR = ../../plugins

EXAMPLE_FILES = fritzbox.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


