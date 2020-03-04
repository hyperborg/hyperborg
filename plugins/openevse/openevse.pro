include(openevse.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = openevse.h

SOURCES = openevse.cpp

TARGET = $$qtLibraryTarget(openevse)

DESTDIR = ../../plugins

EXAMPLE_FILES = openevse.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


