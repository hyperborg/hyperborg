include(enphase_envoy.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = enphase_envoy.h

SOURCES = enphase_envoy.cpp

TARGET = $$qtLibraryTarget(enphase_envoy)

DESTDIR = ../../plugins

EXAMPLE_FILES = enphase_envoy.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


