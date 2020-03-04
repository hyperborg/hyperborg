include(spider.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = spider.h

SOURCES = spider.cpp

TARGET = $$qtLibraryTarget(spider)

DESTDIR = ../../plugins

EXAMPLE_FILES = spider.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


