include(ddwrt.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = ddwrt.h

SOURCES = ddwrt.cpp

TARGET = $$qtLibraryTarget(ddwrt)

DESTDIR = ../../plugins

EXAMPLE_FILES = ddwrt.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


