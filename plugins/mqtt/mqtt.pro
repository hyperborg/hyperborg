include(mqtt.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = mqtt.h

SOURCES = mqtt.cpp

TARGET = $$qtLibraryTarget(mqtt)

DESTDIR = ../../plugins

EXAMPLE_FILES = mqtt.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


