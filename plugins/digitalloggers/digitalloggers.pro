include(digitalloggers.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = digitalloggers.h

SOURCES = digitalloggers.cpp

TARGET = $$qtLibraryTarget(digitalloggers)

DESTDIR = ../../plugins

EXAMPLE_FILES = digitalloggers.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


