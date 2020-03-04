include(facebook.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = facebook.h

SOURCES = facebook.cpp

TARGET = $$qtLibraryTarget(facebook)

DESTDIR = ../../plugins

EXAMPLE_FILES = facebook.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


