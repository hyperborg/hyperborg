include(mqtt_room.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = mqtt_room.h

SOURCES = mqtt_room.cpp

TARGET = $$qtLibraryTarget(mqtt_room)

DESTDIR = ../../plugins

EXAMPLE_FILES = mqtt_room.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


