include(system_health.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = system_health.h

SOURCES = system_health.cpp

TARGET = $$qtLibraryTarget(system_health)

DESTDIR = ../../plugins

EXAMPLE_FILES = system_health.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


