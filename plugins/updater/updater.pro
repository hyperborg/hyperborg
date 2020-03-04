include(updater.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = updater.h

SOURCES = updater.cpp

TARGET = $$qtLibraryTarget(updater)

DESTDIR = ../../plugins

EXAMPLE_FILES = updater.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


