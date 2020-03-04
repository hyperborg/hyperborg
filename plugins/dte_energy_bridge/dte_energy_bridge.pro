include(dte_energy_bridge.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = dte_energy_bridge.h

SOURCES = dte_energy_bridge.cpp

TARGET = $$qtLibraryTarget(dte_energy_bridge)

DESTDIR = ../../plugins

EXAMPLE_FILES = dte_energy_bridge.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


