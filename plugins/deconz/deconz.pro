include(deconz.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = deconz.h

SOURCES = deconz.cpp

TARGET = $$qtLibraryTarget(deconz)

DESTDIR = ../../plugins

EXAMPLE_FILES = deconz.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


