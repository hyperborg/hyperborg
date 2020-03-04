include(foursquare.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = foursquare.h

SOURCES = foursquare.cpp

TARGET = $$qtLibraryTarget(foursquare)

DESTDIR = ../../plugins

EXAMPLE_FILES = foursquare.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


