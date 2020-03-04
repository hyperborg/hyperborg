include(comed_hourly_pricing.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = comed_hourly_pricing.h

SOURCES = comed_hourly_pricing.cpp

TARGET = $$qtLibraryTarget(comed_hourly_pricing)

DESTDIR = ../../plugins

EXAMPLE_FILES = comed_hourly_pricing.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


