include(feedreader.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = feedreader.h

SOURCES = feedreader.cpp

TARGET = $$qtLibraryTarget(feedreader)

DESTDIR = ../../plugins

EXAMPLE_FILES = feedreader.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


