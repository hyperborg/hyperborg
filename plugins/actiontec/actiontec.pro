include(actiontec.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = actiontec.h

SOURCES = actiontec.cpp

TARGET = $$qtLibraryTarget(actiontec)

DESTDIR = ../../plugins

EXAMPLE_FILES = actiontec.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


