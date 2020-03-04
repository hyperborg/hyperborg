include(tuya.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = tuya.h

SOURCES = tuya.cpp

TARGET = $$qtLibraryTarget(tuya)

DESTDIR = ../../plugins

EXAMPLE_FILES = tuya.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


