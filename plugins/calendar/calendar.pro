include(calendar.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = calendar.h

SOURCES = calendar.cpp

TARGET = $$qtLibraryTarget(calendar)

DESTDIR = ../../plugins

EXAMPLE_FILES = calendar.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


