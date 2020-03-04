include(template.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = template.h

SOURCES = template.cpp

TARGET = $$qtLibraryTarget(template)

DESTDIR = ../../plugins

EXAMPLE_FILES = template.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


