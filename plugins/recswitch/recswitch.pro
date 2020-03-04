include(recswitch.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = recswitch.h

SOURCES = recswitch.cpp

TARGET = $$qtLibraryTarget(recswitch)

DESTDIR = ../../plugins

EXAMPLE_FILES = recswitch.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


