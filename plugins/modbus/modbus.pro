include(modbus.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = modbus.h

SOURCES = modbus.cpp

TARGET = $$qtLibraryTarget(modbus)

DESTDIR = ../../plugins

EXAMPLE_FILES = modbus.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


