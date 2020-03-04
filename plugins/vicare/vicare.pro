include(vicare.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = vicare.h

SOURCES = vicare.cpp

TARGET = $$qtLibraryTarget(vicare)

DESTDIR = ../../plugins

EXAMPLE_FILES = vicare.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


