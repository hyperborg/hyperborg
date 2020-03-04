include(rpi_rf.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = rpi_rf.h

SOURCES = rpi_rf.cpp

TARGET = $$qtLibraryTarget(rpi_rf)

DESTDIR = ../../plugins

EXAMPLE_FILES = rpi_rf.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


