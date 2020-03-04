include(google_domains.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = google_domains.h

SOURCES = google_domains.cpp

TARGET = $$qtLibraryTarget(google_domains)

DESTDIR = ../../plugins

EXAMPLE_FILES = google_domains.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


