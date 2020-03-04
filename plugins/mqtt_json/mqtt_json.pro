include(mqtt_json.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = mqtt_json.h

SOURCES = mqtt_json.cpp

TARGET = $$qtLibraryTarget(mqtt_json)

DESTDIR = ../../plugins

EXAMPLE_FILES = mqtt_json.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


