include(greeneye_monitor.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = greeneye_monitor.h

SOURCES = greeneye_monitor.cpp

TARGET = $$qtLibraryTarget(greeneye_monitor)

DESTDIR = ../../plugins

EXAMPLE_FILES = greeneye_monitor.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


