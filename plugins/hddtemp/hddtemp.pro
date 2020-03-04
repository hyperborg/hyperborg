include(hddtemp.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = hddtemp.h

SOURCES = hddtemp.cpp

TARGET = $$qtLibraryTarget(hddtemp)

DESTDIR = ../../plugins

EXAMPLE_FILES = hddtemp.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


