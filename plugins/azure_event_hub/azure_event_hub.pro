include(azure_event_hub.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = azure_event_hub.h

SOURCES = azure_event_hub.cpp

TARGET = $$qtLibraryTarget(azure_event_hub)

DESTDIR = ../../plugins

EXAMPLE_FILES = azure_event_hub.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


