include(azure_service_bus.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = azure_service_bus.h

SOURCES = azure_service_bus.cpp

TARGET = $$qtLibraryTarget(azure_service_bus)

DESTDIR = ../../plugins

EXAMPLE_FILES = azure_service_bus.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


