include(lw12wifi.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = lw12wifi.h

SOURCES = lw12wifi.cpp

TARGET = $$qtLibraryTarget(lw12wifi)

DESTDIR = ../../plugins

EXAMPLE_FILES = lw12wifi.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


