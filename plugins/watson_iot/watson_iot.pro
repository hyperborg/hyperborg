include(watson_iot.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = watson_iot.h

SOURCES = watson_iot.cpp

TARGET = $$qtLibraryTarget(watson_iot)

DESTDIR = ../../plugins

EXAMPLE_FILES = watson_iot.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


