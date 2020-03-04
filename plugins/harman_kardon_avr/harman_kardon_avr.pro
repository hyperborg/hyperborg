include(harman_kardon_avr.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = harman_kardon_avr.h

SOURCES = harman_kardon_avr.cpp

TARGET = $$qtLibraryTarget(harman_kardon_avr)

DESTDIR = ../../plugins

EXAMPLE_FILES = harman_kardon_avr.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


