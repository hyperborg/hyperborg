include(wake_on_lan.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = wake_on_lan.h

SOURCES = wake_on_lan.cpp

TARGET = $$qtLibraryTarget(wake_on_lan)

DESTDIR = ../../plugins

EXAMPLE_FILES = wake_on_lan.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


