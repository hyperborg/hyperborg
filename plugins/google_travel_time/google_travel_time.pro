include(google_travel_time.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = google_travel_time.h

SOURCES = google_travel_time.cpp

TARGET = $$qtLibraryTarget(google_travel_time)

DESTDIR = ../../plugins

EXAMPLE_FILES = google_travel_time.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


