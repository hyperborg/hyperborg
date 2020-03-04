include(unifi_direct.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = unifi_direct.h

SOURCES = unifi_direct.cpp

TARGET = $$qtLibraryTarget(unifi_direct)

DESTDIR = ../../plugins

EXAMPLE_FILES = unifi_direct.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


