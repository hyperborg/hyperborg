include(mythicbeastsdns.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = mythicbeastsdns.h

SOURCES = mythicbeastsdns.cpp

TARGET = $$qtLibraryTarget(mythicbeastsdns)

DESTDIR = ../../plugins

EXAMPLE_FILES = mythicbeastsdns.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


