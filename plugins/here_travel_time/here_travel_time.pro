include(here_travel_time.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = here_travel_time.h

SOURCES = here_travel_time.cpp

TARGET = $$qtLibraryTarget(here_travel_time)

DESTDIR = ../../plugins

EXAMPLE_FILES = here_travel_time.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


