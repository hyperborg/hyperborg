include(linksys_smart.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = linksys_smart.h

SOURCES = linksys_smart.cpp

TARGET = $$qtLibraryTarget(linksys_smart)

DESTDIR = ../../plugins

EXAMPLE_FILES = linksys_smart.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


