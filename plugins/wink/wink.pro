include(wink.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = wink.h

SOURCES = wink.cpp

TARGET = $$qtLibraryTarget(wink)

DESTDIR = ../../plugins

EXAMPLE_FILES = wink.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


