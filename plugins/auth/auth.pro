include(auth.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = auth.h

SOURCES = auth.cpp

TARGET = $$qtLibraryTarget(auth)

DESTDIR = ../../plugins

EXAMPLE_FILES = auth.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


