include(reddit.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = reddit.h

SOURCES = reddit.cpp

TARGET = $$qtLibraryTarget(reddit)

DESTDIR = ../../plugins

EXAMPLE_FILES = reddit.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


