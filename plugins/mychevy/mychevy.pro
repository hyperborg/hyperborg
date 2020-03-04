include(mychevy.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = mychevy.h

SOURCES = mychevy.cpp

TARGET = $$qtLibraryTarget(mychevy)

DESTDIR = ../../plugins

EXAMPLE_FILES = mychevy.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


