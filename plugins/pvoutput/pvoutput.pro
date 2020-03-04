include(pvoutput.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = pvoutput.h

SOURCES = pvoutput.cpp

TARGET = $$qtLibraryTarget(pvoutput)

DESTDIR = ../../plugins

EXAMPLE_FILES = pvoutput.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


