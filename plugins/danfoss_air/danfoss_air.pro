include(danfoss_air.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = danfoss_air.h

SOURCES = danfoss_air.cpp

TARGET = $$qtLibraryTarget(danfoss_air)

DESTDIR = ../../plugins

EXAMPLE_FILES = danfoss_air.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


