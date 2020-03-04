include(ue_smart_radio.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = ue_smart_radio.h

SOURCES = ue_smart_radio.cpp

TARGET = $$qtLibraryTarget(ue_smart_radio)

DESTDIR = ../../plugins

EXAMPLE_FILES = ue_smart_radio.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


