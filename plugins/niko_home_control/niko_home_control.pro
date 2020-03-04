include(niko_home_control.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = niko_home_control.h

SOURCES = niko_home_control.cpp

TARGET = $$qtLibraryTarget(niko_home_control)

DESTDIR = ../../plugins

EXAMPLE_FILES = niko_home_control.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


