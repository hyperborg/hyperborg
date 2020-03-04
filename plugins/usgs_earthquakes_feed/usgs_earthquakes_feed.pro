include(usgs_earthquakes_feed.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = usgs_earthquakes_feed.h

SOURCES = usgs_earthquakes_feed.cpp

TARGET = $$qtLibraryTarget(usgs_earthquakes_feed)

DESTDIR = ../../plugins

EXAMPLE_FILES = usgs_earthquakes_feed.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


