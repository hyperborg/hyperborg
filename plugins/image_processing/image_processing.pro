include(image_processing.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = image_processing.h

SOURCES = image_processing.cpp

TARGET = $$qtLibraryTarget(image_processing)

DESTDIR = ../../plugins

EXAMPLE_FILES = image_processing.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


