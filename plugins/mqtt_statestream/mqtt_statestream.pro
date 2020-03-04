include(mqtt_statestream.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = mqtt_statestream.h

SOURCES = mqtt_statestream.cpp

TARGET = $$qtLibraryTarget(mqtt_statestream)

DESTDIR = ../../plugins

EXAMPLE_FILES = mqtt_statestream.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


