include(ee_brightbox.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = ee_brightbox.h

SOURCES = ee_brightbox.cpp

TARGET = $$qtLibraryTarget(ee_brightbox)

DESTDIR = ../../plugins

EXAMPLE_FILES = ee_brightbox.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


