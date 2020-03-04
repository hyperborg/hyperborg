include(device_sun_light_trigger.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = device_sun_light_trigger.h

SOURCES = device_sun_light_trigger.cpp

TARGET = $$qtLibraryTarget(device_sun_light_trigger)

DESTDIR = ../../plugins

EXAMPLE_FILES = device_sun_light_trigger.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


