include(skybell.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = skybell.h

SOURCES = skybell.cpp

TARGET = $$qtLibraryTarget(skybell)

DESTDIR = ../../plugins

EXAMPLE_FILES = skybell.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


