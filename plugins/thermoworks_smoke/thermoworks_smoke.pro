include(thermoworks_smoke.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = thermoworks_smoke.h

SOURCES = thermoworks_smoke.cpp

TARGET = $$qtLibraryTarget(thermoworks_smoke)

DESTDIR = ../../plugins

EXAMPLE_FILES = thermoworks_smoke.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


