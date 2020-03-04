include(google_maps.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = google_maps.h

SOURCES = google_maps.cpp

TARGET = $$qtLibraryTarget(google_maps)

DESTDIR = ../../plugins

EXAMPLE_FILES = google_maps.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


