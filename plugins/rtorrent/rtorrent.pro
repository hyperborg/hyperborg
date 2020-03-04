include(rtorrent.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = rtorrent.h

SOURCES = rtorrent.cpp

TARGET = $$qtLibraryTarget(rtorrent)

DESTDIR = ../../plugins

EXAMPLE_FILES = rtorrent.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


