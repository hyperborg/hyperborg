include(binary_sensor.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = binary_sensor.h

SOURCES = binary_sensor.cpp

TARGET = $$qtLibraryTarget(binary_sensor)

DESTDIR = ../../plugins

EXAMPLE_FILES = binary_sensor.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


