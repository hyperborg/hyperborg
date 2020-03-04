include(rocketchat.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = rocketchat.h

SOURCES = rocketchat.cpp

TARGET = $$qtLibraryTarget(rocketchat)

DESTDIR = ../../plugins

EXAMPLE_FILES = rocketchat.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


