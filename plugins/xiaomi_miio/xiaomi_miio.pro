include(xiaomi_miio.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = xiaomi_miio.h

SOURCES = xiaomi_miio.cpp

TARGET = $$qtLibraryTarget(xiaomi_miio)

DESTDIR = ../../plugins

EXAMPLE_FILES = xiaomi_miio.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


