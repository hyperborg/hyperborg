include(lg_soundbar.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = lg_soundbar.h

SOURCES = lg_soundbar.cpp

TARGET = $$qtLibraryTarget(lg_soundbar)

DESTDIR = ../../plugins

EXAMPLE_FILES = lg_soundbar.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


