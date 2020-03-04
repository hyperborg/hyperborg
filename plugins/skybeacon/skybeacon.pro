include(skybeacon.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = skybeacon.h

SOURCES = skybeacon.cpp

TARGET = $$qtLibraryTarget(skybeacon)

DESTDIR = ../../plugins

EXAMPLE_FILES = skybeacon.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


