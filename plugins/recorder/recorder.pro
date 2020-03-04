include(recorder.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = recorder.h

SOURCES = recorder.cpp

TARGET = $$qtLibraryTarget(recorder)

DESTDIR = ../../plugins

EXAMPLE_FILES = recorder.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


