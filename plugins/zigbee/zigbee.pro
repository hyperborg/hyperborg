include(zigbee.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = zigbee.h

SOURCES = zigbee.cpp

TARGET = $$qtLibraryTarget(zigbee)

DESTDIR = ../../plugins

EXAMPLE_FILES = zigbee.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


