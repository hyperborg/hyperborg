include(rpi_pfio.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = rpi_pfio.h

SOURCES = rpi_pfio.cpp

TARGET = $$qtLibraryTarget(rpi_pfio)

DESTDIR = ../../plugins

EXAMPLE_FILES = rpi_pfio.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


