include(eufy.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = eufy.h

SOURCES = eufy.cpp

TARGET = $$qtLibraryTarget(eufy)

DESTDIR = ../../plugins

EXAMPLE_FILES = eufy.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


