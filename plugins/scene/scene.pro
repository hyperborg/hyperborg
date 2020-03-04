include(scene.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = scene.h

SOURCES = scene.cpp

TARGET = $$qtLibraryTarget(scene)

DESTDIR = ../../plugins

EXAMPLE_FILES = scene.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


