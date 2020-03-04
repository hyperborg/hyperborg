include(notify.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = notify.h

SOURCES = notify.cpp

TARGET = $$qtLibraryTarget(notify)

DESTDIR = ../../plugins

EXAMPLE_FILES = notify.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


