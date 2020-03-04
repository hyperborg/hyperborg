include(august.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = august.h

SOURCES = august.cpp

TARGET = $$qtLibraryTarget(august)

DESTDIR = ../../plugins

EXAMPLE_FILES = august.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


