include(homekit.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = homekit.h

SOURCES = homekit.cpp

TARGET = $$qtLibraryTarget(homekit)

DESTDIR = ../../plugins

EXAMPLE_FILES = homekit.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


