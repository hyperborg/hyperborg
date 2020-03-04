include(google_cloud.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = google_cloud.h

SOURCES = google_cloud.cpp

TARGET = $$qtLibraryTarget(google_cloud)

DESTDIR = ../../plugins

EXAMPLE_FILES = google_cloud.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


