include(no_ip.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = no_ip.h

SOURCES = no_ip.cpp

TARGET = $$qtLibraryTarget(no_ip)

DESTDIR = ../../plugins

EXAMPLE_FILES = no_ip.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


