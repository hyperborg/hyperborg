include(automation.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = automation.h

SOURCES = automation.cpp

TARGET = $$qtLibraryTarget(automation)

DESTDIR = ../../plugins

EXAMPLE_FILES = automation.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


