include(goalfeed.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = goalfeed.h

SOURCES = goalfeed.cpp

TARGET = $$qtLibraryTarget(goalfeed)

DESTDIR = ../../plugins

EXAMPLE_FILES = goalfeed.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


