include(aftership.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = aftership.h

SOURCES = aftership.cpp

TARGET = $$qtLibraryTarget(aftership)

DESTDIR = ../../plugins

EXAMPLE_FILES = aftership.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


