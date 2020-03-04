include(time_date.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = time_date.h

SOURCES = time_date.cpp

TARGET = $$qtLibraryTarget(time_date)

DESTDIR = ../../plugins

EXAMPLE_FILES = time_date.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


