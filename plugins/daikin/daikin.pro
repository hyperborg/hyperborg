include(daikin.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = daikin.h

SOURCES = daikin.cpp

TARGET = $$qtLibraryTarget(daikin)

DESTDIR = ../../plugins

EXAMPLE_FILES = daikin.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


