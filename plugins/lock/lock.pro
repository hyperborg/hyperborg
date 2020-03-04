include(lock.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = lock.h

SOURCES = lock.cpp

TARGET = $$qtLibraryTarget(lock)

DESTDIR = ../../plugins

EXAMPLE_FILES = lock.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


