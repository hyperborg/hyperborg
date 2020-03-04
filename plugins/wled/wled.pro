include(wled.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = wled.h

SOURCES = wled.cpp

TARGET = $$qtLibraryTarget(wled)

DESTDIR = ../../plugins

EXAMPLE_FILES = wled.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


