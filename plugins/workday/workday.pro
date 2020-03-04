include(workday.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = workday.h

SOURCES = workday.cpp

TARGET = $$qtLibraryTarget(workday)

DESTDIR = ../../plugins

EXAMPLE_FILES = workday.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


