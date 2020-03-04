include(emoncms_history.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = emoncms_history.h

SOURCES = emoncms_history.cpp

TARGET = $$qtLibraryTarget(emoncms_history)

DESTDIR = ../../plugins

EXAMPLE_FILES = emoncms_history.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


