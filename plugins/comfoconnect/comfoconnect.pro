include(comfoconnect.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = comfoconnect.h

SOURCES = comfoconnect.cpp

TARGET = $$qtLibraryTarget(comfoconnect)

DESTDIR = ../../plugins

EXAMPLE_FILES = comfoconnect.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


