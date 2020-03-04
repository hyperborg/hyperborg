include(supervisord.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = supervisord.h

SOURCES = supervisord.cpp

TARGET = $$qtLibraryTarget(supervisord)

DESTDIR = ../../plugins

EXAMPLE_FILES = supervisord.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


