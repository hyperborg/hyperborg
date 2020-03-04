include(google_assistant.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = google_assistant.h

SOURCES = google_assistant.cpp

TARGET = $$qtLibraryTarget(google_assistant)

DESTDIR = ../../plugins

EXAMPLE_FILES = google_assistant.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


