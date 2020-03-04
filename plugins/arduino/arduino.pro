include(arduino.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = arduino.h

SOURCES = arduino.cpp

TARGET = $$qtLibraryTarget(arduino)

DESTDIR = ../../plugins

EXAMPLE_FILES = arduino.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


