include(apple_tv.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = apple_tv.h

SOURCES = apple_tv.cpp

TARGET = $$qtLibraryTarget(apple_tv)

DESTDIR = ../../plugins

EXAMPLE_FILES = apple_tv.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


