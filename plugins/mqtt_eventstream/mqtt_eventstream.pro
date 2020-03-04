include(mqtt_eventstream.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = mqtt_eventstream.h

SOURCES = mqtt_eventstream.cpp

TARGET = $$qtLibraryTarget(mqtt_eventstream)

DESTDIR = ../../plugins

EXAMPLE_FILES = mqtt_eventstream.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


