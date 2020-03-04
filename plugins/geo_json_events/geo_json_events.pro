include(geo_json_events.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = geo_json_events.h

SOURCES = geo_json_events.cpp

TARGET = $$qtLibraryTarget(geo_json_events)

DESTDIR = ../../plugins

EXAMPLE_FILES = geo_json_events.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


