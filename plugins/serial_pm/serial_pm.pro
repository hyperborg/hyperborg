include(serial_pm.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = serial_pm.h

SOURCES = serial_pm.cpp

TARGET = $$qtLibraryTarget(serial_pm)

DESTDIR = ../../plugins

EXAMPLE_FILES = serial_pm.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


