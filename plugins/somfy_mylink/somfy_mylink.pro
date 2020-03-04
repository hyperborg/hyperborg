include(somfy_mylink.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = somfy_mylink.h

SOURCES = somfy_mylink.cpp

TARGET = $$qtLibraryTarget(somfy_mylink)

DESTDIR = ../../plugins

EXAMPLE_FILES = somfy_mylink.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


