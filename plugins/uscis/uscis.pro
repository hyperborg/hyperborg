include(uscis.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = uscis.h

SOURCES = uscis.cpp

TARGET = $$qtLibraryTarget(uscis)

DESTDIR = ../../plugins

EXAMPLE_FILES = uscis.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


