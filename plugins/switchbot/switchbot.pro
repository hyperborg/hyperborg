include(switchbot.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = switchbot.h

SOURCES = switchbot.cpp

TARGET = $$qtLibraryTarget(switchbot)

DESTDIR = ../../plugins

EXAMPLE_FILES = switchbot.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


