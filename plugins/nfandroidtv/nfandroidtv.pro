include(nfandroidtv.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = nfandroidtv.h

SOURCES = nfandroidtv.cpp

TARGET = $$qtLibraryTarget(nfandroidtv)

DESTDIR = ../../plugins

EXAMPLE_FILES = nfandroidtv.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


