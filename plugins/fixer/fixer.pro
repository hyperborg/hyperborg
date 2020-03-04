include(fixer.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = fixer.h

SOURCES = fixer.cpp

TARGET = $$qtLibraryTarget(fixer)

DESTDIR = ../../plugins

EXAMPLE_FILES = fixer.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


