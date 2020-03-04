include(soma.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = soma.h

SOURCES = soma.cpp

TARGET = $$qtLibraryTarget(soma)

DESTDIR = ../../plugins

EXAMPLE_FILES = soma.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


