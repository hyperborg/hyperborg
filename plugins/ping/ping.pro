include(ping.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = ping.h

SOURCES = ping.cpp

TARGET = $$qtLibraryTarget(ping)

DESTDIR = ../../plugins

EXAMPLE_FILES = ping.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


