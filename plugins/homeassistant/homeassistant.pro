include(homeassistant.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = homeassistant.h

SOURCES = homeassistant.cpp

TARGET = $$qtLibraryTarget(homeassistant)

DESTDIR = ../../plugins

EXAMPLE_FILES = homeassistant.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


