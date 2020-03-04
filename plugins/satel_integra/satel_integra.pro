include(satel_integra.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = satel_integra.h

SOURCES = satel_integra.cpp

TARGET = $$qtLibraryTarget(satel_integra)

DESTDIR = ../../plugins

EXAMPLE_FILES = satel_integra.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


