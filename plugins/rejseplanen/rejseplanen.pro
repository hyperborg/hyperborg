include(rejseplanen.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = rejseplanen.h

SOURCES = rejseplanen.cpp

TARGET = $$qtLibraryTarget(rejseplanen)

DESTDIR = ../../plugins

EXAMPLE_FILES = rejseplanen.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


