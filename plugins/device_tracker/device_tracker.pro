include(device_tracker.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = device_tracker.h

SOURCES = device_tracker.cpp

TARGET = $$qtLibraryTarget(device_tracker)

DESTDIR = ../../plugins

EXAMPLE_FILES = device_tracker.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


