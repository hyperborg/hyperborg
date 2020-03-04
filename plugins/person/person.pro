include(person.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = person.h

SOURCES = person.cpp

TARGET = $$qtLibraryTarget(person)

DESTDIR = ../../plugins

EXAMPLE_FILES = person.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


