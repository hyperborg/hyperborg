include(coolmaster.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = coolmaster.h

SOURCES = coolmaster.cpp

TARGET = $$qtLibraryTarget(coolmaster)

DESTDIR = ../../plugins

EXAMPLE_FILES = coolmaster.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


