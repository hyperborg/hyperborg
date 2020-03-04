include(opengarage.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = opengarage.h

SOURCES = opengarage.cpp

TARGET = $$qtLibraryTarget(opengarage)

DESTDIR = ../../plugins

EXAMPLE_FILES = opengarage.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


