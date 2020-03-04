include(google.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = google.h

SOURCES = google.cpp

TARGET = $$qtLibraryTarget(google)

DESTDIR = ../../plugins

EXAMPLE_FILES = google.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


