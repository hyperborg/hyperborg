include(openalpr_local.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = openalpr_local.h

SOURCES = openalpr_local.cpp

TARGET = $$qtLibraryTarget(openalpr_local)

DESTDIR = ../../plugins

EXAMPLE_FILES = openalpr_local.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


