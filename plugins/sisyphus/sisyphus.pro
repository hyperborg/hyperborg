include(sisyphus.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = sisyphus.h

SOURCES = sisyphus.cpp

TARGET = $$qtLibraryTarget(sisyphus)

DESTDIR = ../../plugins

EXAMPLE_FILES = sisyphus.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


