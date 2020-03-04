include(seven_segments.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = seven_segments.h

SOURCES = seven_segments.cpp

TARGET = $$qtLibraryTarget(seven_segments)

DESTDIR = ../../plugins

EXAMPLE_FILES = seven_segments.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


