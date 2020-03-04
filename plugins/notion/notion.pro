include(notion.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = notion.h

SOURCES = notion.cpp

TARGET = $$qtLibraryTarget(notion)

DESTDIR = ../../plugins

EXAMPLE_FILES = notion.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


