include(fido.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = fido.h

SOURCES = fido.cpp

TARGET = $$qtLibraryTarget(fido)

DESTDIR = ../../plugins

EXAMPLE_FILES = fido.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


