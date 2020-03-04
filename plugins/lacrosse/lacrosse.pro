include(lacrosse.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = lacrosse.h

SOURCES = lacrosse.cpp

TARGET = $$qtLibraryTarget(lacrosse)

DESTDIR = ../../plugins

EXAMPLE_FILES = lacrosse.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


