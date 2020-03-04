include(braviatv.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = braviatv.h

SOURCES = braviatv.cpp

TARGET = $$qtLibraryTarget(braviatv)

DESTDIR = ../../plugins

EXAMPLE_FILES = braviatv.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


