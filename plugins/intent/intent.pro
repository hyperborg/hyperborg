include(intent.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = intent.h

SOURCES = intent.cpp

TARGET = $$qtLibraryTarget(intent)

DESTDIR = ../../plugins

EXAMPLE_FILES = intent.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


