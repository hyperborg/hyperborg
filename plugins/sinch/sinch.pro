include(sinch.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = sinch.h

SOURCES = sinch.cpp

TARGET = $$qtLibraryTarget(sinch)

DESTDIR = ../../plugins

EXAMPLE_FILES = sinch.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


