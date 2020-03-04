include(ads.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = ads.h

SOURCES = ads.cpp

TARGET = $$qtLibraryTarget(ads)

DESTDIR = ../../plugins

EXAMPLE_FILES = ads.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


