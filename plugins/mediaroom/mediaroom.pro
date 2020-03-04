include(mediaroom.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = mediaroom.h

SOURCES = mediaroom.cpp

TARGET = $$qtLibraryTarget(mediaroom)

DESTDIR = ../../plugins

EXAMPLE_FILES = mediaroom.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


