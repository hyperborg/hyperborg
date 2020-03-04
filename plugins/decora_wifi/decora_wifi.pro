include(decora_wifi.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = decora_wifi.h

SOURCES = decora_wifi.cpp

TARGET = $$qtLibraryTarget(decora_wifi)

DESTDIR = ../../plugins

EXAMPLE_FILES = decora_wifi.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


