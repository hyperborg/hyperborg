include(camera.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = camera.h

SOURCES = camera.cpp

TARGET = $$qtLibraryTarget(camera)

DESTDIR = ../../plugins

EXAMPLE_FILES = camera.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


