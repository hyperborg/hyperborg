include(bluetooth_le_tracker.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = bluetooth_le_tracker.h

SOURCES = bluetooth_le_tracker.cpp

TARGET = $$qtLibraryTarget(bluetooth_le_tracker)

DESTDIR = ../../plugins

EXAMPLE_FILES = bluetooth_le_tracker.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


