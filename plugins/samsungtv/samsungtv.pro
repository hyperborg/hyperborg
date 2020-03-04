include(samsungtv.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = samsungtv.h

SOURCES = samsungtv.cpp

TARGET = $$qtLibraryTarget(samsungtv)

DESTDIR = ../../plugins

EXAMPLE_FILES = samsungtv.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


