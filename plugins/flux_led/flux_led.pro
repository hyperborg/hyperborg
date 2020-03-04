include(flux_led.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = flux_led.h

SOURCES = flux_led.cpp

TARGET = $$qtLibraryTarget(flux_led)

DESTDIR = ../../plugins

EXAMPLE_FILES = flux_led.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


