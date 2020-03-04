include(ziggo_mediabox_xl.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = ziggo_mediabox_xl.h

SOURCES = ziggo_mediabox_xl.cpp

TARGET = $$qtLibraryTarget(ziggo_mediabox_xl)

DESTDIR = ../../plugins

EXAMPLE_FILES = ziggo_mediabox_xl.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


