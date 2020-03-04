include(wunderlist.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = wunderlist.h

SOURCES = wunderlist.cpp

TARGET = $$qtLibraryTarget(wunderlist)

DESTDIR = ../../plugins

EXAMPLE_FILES = wunderlist.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


