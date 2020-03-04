include(evohome.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = evohome.h

SOURCES = evohome.cpp

TARGET = $$qtLibraryTarget(evohome)

DESTDIR = ../../plugins

EXAMPLE_FILES = evohome.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


