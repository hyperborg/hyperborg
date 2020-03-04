include(baidu.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = baidu.h

SOURCES = baidu.cpp

TARGET = $$qtLibraryTarget(baidu)

DESTDIR = ../../plugins

EXAMPLE_FILES = baidu.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


