include(qwikswitch.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = qwikswitch.h

SOURCES = qwikswitch.cpp

TARGET = $$qtLibraryTarget(qwikswitch)

DESTDIR = ../../plugins

EXAMPLE_FILES = qwikswitch.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


