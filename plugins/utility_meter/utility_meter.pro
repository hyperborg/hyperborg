include(utility_meter.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = utility_meter.h

SOURCES = utility_meter.cpp

TARGET = $$qtLibraryTarget(utility_meter)

DESTDIR = ../../plugins

EXAMPLE_FILES = utility_meter.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


