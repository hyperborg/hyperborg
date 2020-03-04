include(nuimo_controller.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = nuimo_controller.h

SOURCES = nuimo_controller.cpp

TARGET = $$qtLibraryTarget(nuimo_controller)

DESTDIR = ../../plugins

EXAMPLE_FILES = nuimo_controller.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


