include(bmw_connected_drive.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = bmw_connected_drive.h

SOURCES = bmw_connected_drive.cpp

TARGET = $$qtLibraryTarget(bmw_connected_drive)

DESTDIR = ../../plugins

EXAMPLE_FILES = bmw_connected_drive.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


