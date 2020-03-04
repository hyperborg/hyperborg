include(enigma2.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = enigma2.h

SOURCES = enigma2.cpp

TARGET = $$qtLibraryTarget(enigma2)

DESTDIR = ../../plugins

EXAMPLE_FILES = enigma2.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


