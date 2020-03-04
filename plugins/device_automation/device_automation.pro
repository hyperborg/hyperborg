include(device_automation.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = device_automation.h

SOURCES = device_automation.cpp

TARGET = $$qtLibraryTarget(device_automation)

DESTDIR = ../../plugins

EXAMPLE_FILES = device_automation.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


