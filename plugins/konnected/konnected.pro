include(konnected.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = konnected.h

SOURCES = konnected.cpp

TARGET = $$qtLibraryTarget(konnected)

DESTDIR = ../../plugins

EXAMPLE_FILES = konnected.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


