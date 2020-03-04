include(google_pubsub.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = google_pubsub.h

SOURCES = google_pubsub.cpp

TARGET = $$qtLibraryTarget(google_pubsub)

DESTDIR = ../../plugins

EXAMPLE_FILES = google_pubsub.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


