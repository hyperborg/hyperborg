include(vlc.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = vlc.h

SOURCES = vlc.cpp

TARGET = $$qtLibraryTarget(vlc)

DESTDIR = ../../plugins

EXAMPLE_FILES = vlc.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


