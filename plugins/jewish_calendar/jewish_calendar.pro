include(jewish_calendar.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = jewish_calendar.h

SOURCES = jewish_calendar.cpp

TARGET = $$qtLibraryTarget(jewish_calendar)

DESTDIR = ../../plugins

EXAMPLE_FILES = jewish_calendar.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


