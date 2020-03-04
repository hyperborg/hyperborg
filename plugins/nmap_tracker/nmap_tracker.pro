include(nmap_tracker.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = nmap_tracker.h

SOURCES = nmap_tracker.cpp

TARGET = $$qtLibraryTarget(nmap_tracker)

DESTDIR = ../../plugins

EXAMPLE_FILES = nmap_tracker.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


