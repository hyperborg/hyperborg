include(xiaomi_aqara.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = xiaomi_aqara.h

SOURCES = xiaomi_aqara.cpp

TARGET = $$qtLibraryTarget(xiaomi_aqara)

DESTDIR = ../../plugins

EXAMPLE_FILES = xiaomi_aqara.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


