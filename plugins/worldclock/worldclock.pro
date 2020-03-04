include(worldclock.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = worldclock.h

SOURCES = worldclock.cpp

TARGET = $$qtLibraryTarget(worldclock)

DESTDIR = ../../plugins

EXAMPLE_FILES = worldclock.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


