include(emby.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = emby.h

SOURCES = emby.cpp

TARGET = $$qtLibraryTarget(emby)

DESTDIR = ../../plugins

EXAMPLE_FILES = emby.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


