include(google_translate.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = google_translate.h

SOURCES = google_translate.cpp

TARGET = $$qtLibraryTarget(google_translate)

DESTDIR = ../../plugins

EXAMPLE_FILES = google_translate.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


