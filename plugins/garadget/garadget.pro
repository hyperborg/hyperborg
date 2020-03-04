include(garadget.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = garadget.h

SOURCES = garadget.cpp

TARGET = $$qtLibraryTarget(garadget)

DESTDIR = ../../plugins

EXAMPLE_FILES = garadget.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


