include(bluesound.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = bluesound.h

SOURCES = bluesound.cpp

TARGET = $$qtLibraryTarget(bluesound)

DESTDIR = ../../plugins

EXAMPLE_FILES = bluesound.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


