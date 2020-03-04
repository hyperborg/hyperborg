include(mochad.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = mochad.h

SOURCES = mochad.cpp

TARGET = $$qtLibraryTarget(mochad)

DESTDIR = ../../plugins

EXAMPLE_FILES = mochad.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


