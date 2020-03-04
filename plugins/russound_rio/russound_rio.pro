include(russound_rio.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = russound_rio.h

SOURCES = russound_rio.cpp

TARGET = $$qtLibraryTarget(russound_rio)

DESTDIR = ../../plugins

EXAMPLE_FILES = russound_rio.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


