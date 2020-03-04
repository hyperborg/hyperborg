include(plum_lightpad.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = plum_lightpad.h

SOURCES = plum_lightpad.cpp

TARGET = $$qtLibraryTarget(plum_lightpad)

DESTDIR = ../../plugins

EXAMPLE_FILES = plum_lightpad.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


