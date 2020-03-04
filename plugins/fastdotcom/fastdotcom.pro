include(fastdotcom.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = fastdotcom.h

SOURCES = fastdotcom.cpp

TARGET = $$qtLibraryTarget(fastdotcom)

DESTDIR = ../../plugins

EXAMPLE_FILES = fastdotcom.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


