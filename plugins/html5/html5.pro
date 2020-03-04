include(html5.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = html5.h

SOURCES = html5.cpp

TARGET = $$qtLibraryTarget(html5)

DESTDIR = ../../plugins

EXAMPLE_FILES = html5.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


