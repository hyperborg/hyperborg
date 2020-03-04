include(emulated_roku.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = emulated_roku.h

SOURCES = emulated_roku.cpp

TARGET = $$qtLibraryTarget(emulated_roku)

DESTDIR = ../../plugins

EXAMPLE_FILES = emulated_roku.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


