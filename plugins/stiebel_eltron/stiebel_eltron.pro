include(stiebel_eltron.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = stiebel_eltron.h

SOURCES = stiebel_eltron.cpp

TARGET = $$qtLibraryTarget(stiebel_eltron)

DESTDIR = ../../plugins

EXAMPLE_FILES = stiebel_eltron.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


