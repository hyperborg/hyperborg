include(mfi.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = mfi.h

SOURCES = mfi.cpp

TARGET = $$qtLibraryTarget(mfi)

DESTDIR = ../../plugins

EXAMPLE_FILES = mfi.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


