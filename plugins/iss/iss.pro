include(iss.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = iss.h

SOURCES = iss.cpp

TARGET = $$qtLibraryTarget(iss)

DESTDIR = ../../plugins

EXAMPLE_FILES = iss.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


