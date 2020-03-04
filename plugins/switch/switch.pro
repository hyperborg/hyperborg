include(switch.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = switch.h

SOURCES = switch.cpp

TARGET = $$qtLibraryTarget(switch)

DESTDIR = ../../plugins

EXAMPLE_FILES = switch.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


