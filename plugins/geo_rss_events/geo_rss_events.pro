include(geo_rss_events.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = geo_rss_events.h

SOURCES = geo_rss_events.cpp

TARGET = $$qtLibraryTarget(geo_rss_events)

DESTDIR = ../../plugins

EXAMPLE_FILES = geo_rss_events.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


