include(torque.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = torque.h

SOURCES = torque.cpp

TARGET = $$qtLibraryTarget(torque)

DESTDIR = ../../plugins

EXAMPLE_FILES = torque.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


