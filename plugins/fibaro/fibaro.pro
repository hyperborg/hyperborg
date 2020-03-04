include(fibaro.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = fibaro.h

SOURCES = fibaro.cpp

TARGET = $$qtLibraryTarget(fibaro)

DESTDIR = ../../plugins

EXAMPLE_FILES = fibaro.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


