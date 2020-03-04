include(integration.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = integration.h

SOURCES = integration.cpp

TARGET = $$qtLibraryTarget(integration)

DESTDIR = ../../plugins

EXAMPLE_FILES = integration.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


