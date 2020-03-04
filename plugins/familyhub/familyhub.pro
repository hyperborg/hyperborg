include(familyhub.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = familyhub.h

SOURCES = familyhub.cpp

TARGET = $$qtLibraryTarget(familyhub)

DESTDIR = ../../plugins

EXAMPLE_FILES = familyhub.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


