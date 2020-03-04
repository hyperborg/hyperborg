include(fritzbox_netmonitor.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = fritzbox_netmonitor.h

SOURCES = fritzbox_netmonitor.cpp

TARGET = $$qtLibraryTarget(fritzbox_netmonitor)

DESTDIR = ../../plugins

EXAMPLE_FILES = fritzbox_netmonitor.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


