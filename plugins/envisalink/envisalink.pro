include(envisalink.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = envisalink.h

SOURCES = envisalink.cpp

TARGET = $$qtLibraryTarget(envisalink)

DESTDIR = ../../plugins

EXAMPLE_FILES = envisalink.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


