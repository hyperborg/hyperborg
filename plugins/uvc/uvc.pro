include(uvc.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = uvc.h

SOURCES = uvc.cpp

TARGET = $$qtLibraryTarget(uvc)

DESTDIR = ../../plugins

EXAMPLE_FILES = uvc.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


