include(hyperion.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = hyperion.h

SOURCES = hyperion.cpp

TARGET = $$qtLibraryTarget(hyperion)

DESTDIR = ../../plugins

EXAMPLE_FILES = hyperion.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


