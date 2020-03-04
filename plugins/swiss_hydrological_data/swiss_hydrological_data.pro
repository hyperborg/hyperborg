include(swiss_hydrological_data.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = swiss_hydrological_data.h

SOURCES = swiss_hydrological_data.cpp

TARGET = $$qtLibraryTarget(swiss_hydrological_data)

DESTDIR = ../../plugins

EXAMPLE_FILES = swiss_hydrological_data.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


