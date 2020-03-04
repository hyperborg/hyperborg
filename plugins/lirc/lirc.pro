include(lirc.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = lirc.h

SOURCES = lirc.cpp

TARGET = $$qtLibraryTarget(lirc)

DESTDIR = ../../plugins

EXAMPLE_FILES = lirc.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


