include(caldav.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = caldav.h

SOURCES = caldav.cpp

TARGET = $$qtLibraryTarget(caldav)

DESTDIR = ../../plugins

EXAMPLE_FILES = caldav.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


