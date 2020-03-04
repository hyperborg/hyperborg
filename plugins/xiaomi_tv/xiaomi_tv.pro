include(xiaomi_tv.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = xiaomi_tv.h

SOURCES = xiaomi_tv.cpp

TARGET = $$qtLibraryTarget(xiaomi_tv)

DESTDIR = ../../plugins

EXAMPLE_FILES = xiaomi_tv.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


