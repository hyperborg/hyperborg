include(manual_mqtt.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = manual_mqtt.h

SOURCES = manual_mqtt.cpp

TARGET = $$qtLibraryTarget(manual_mqtt)

DESTDIR = ../../plugins

EXAMPLE_FILES = manual_mqtt.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


