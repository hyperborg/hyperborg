include(filesize.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = filesize.h

SOURCES = filesize.cpp

TARGET = $$qtLibraryTarget(filesize)

DESTDIR = ../../plugins

EXAMPLE_FILES = filesize.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


