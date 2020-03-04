include(mitemp_bt.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = mitemp_bt.h

SOURCES = mitemp_bt.cpp

TARGET = $$qtLibraryTarget(mitemp_bt)

DESTDIR = ../../plugins

EXAMPLE_FILES = mitemp_bt.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


