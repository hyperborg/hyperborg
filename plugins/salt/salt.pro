include(salt.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = salt.h

SOURCES = salt.cpp

TARGET = $$qtLibraryTarget(salt)

DESTDIR = ../../plugins

EXAMPLE_FILES = salt.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


