include(fritzbox_callmonitor.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = fritzbox_callmonitor.h

SOURCES = fritzbox_callmonitor.cpp

TARGET = $$qtLibraryTarget(fritzbox_callmonitor)

DESTDIR = ../../plugins

EXAMPLE_FILES = fritzbox_callmonitor.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


