include(universal.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = universal.h

SOURCES = universal.cpp

TARGET = $$qtLibraryTarget(universal)

DESTDIR = ../../plugins

EXAMPLE_FILES = universal.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


