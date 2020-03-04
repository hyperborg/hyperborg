include(flunearyou.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = flunearyou.h

SOURCES = flunearyou.cpp

TARGET = $$qtLibraryTarget(flunearyou)

DESTDIR = ../../plugins

EXAMPLE_FILES = flunearyou.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


