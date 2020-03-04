include(switchmate.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = switchmate.h

SOURCES = switchmate.cpp

TARGET = $$qtLibraryTarget(switchmate)

DESTDIR = ../../plugins

EXAMPLE_FILES = switchmate.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


