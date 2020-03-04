include(thinkingcleaner.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = thinkingcleaner.h

SOURCES = thinkingcleaner.cpp

TARGET = $$qtLibraryTarget(thinkingcleaner)

DESTDIR = ../../plugins

EXAMPLE_FILES = thinkingcleaner.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


