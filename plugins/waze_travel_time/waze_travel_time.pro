include(waze_travel_time.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = waze_travel_time.h

SOURCES = waze_travel_time.cpp

TARGET = $$qtLibraryTarget(waze_travel_time)

DESTDIR = ../../plugins

EXAMPLE_FILES = waze_travel_time.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


