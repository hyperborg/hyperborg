include(simplepush.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = simplepush.h

SOURCES = simplepush.cpp

TARGET = $$qtLibraryTarget(simplepush)

DESTDIR = ../../plugins

EXAMPLE_FILES = simplepush.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


