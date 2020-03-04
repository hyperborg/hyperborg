include(cppm_tracker.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = cppm_tracker.h

SOURCES = cppm_tracker.cpp

TARGET = $$qtLibraryTarget(cppm_tracker)

DESTDIR = ../../plugins

EXAMPLE_FILES = cppm_tracker.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


