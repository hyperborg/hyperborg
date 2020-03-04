include(openhardwaremonitor.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = openhardwaremonitor.h

SOURCES = openhardwaremonitor.cpp

TARGET = $$qtLibraryTarget(openhardwaremonitor)

DESTDIR = ../../plugins

EXAMPLE_FILES = openhardwaremonitor.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


