include(xbox_live.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = xbox_live.h

SOURCES = xbox_live.cpp

TARGET = $$qtLibraryTarget(xbox_live)

DESTDIR = ../../plugins

EXAMPLE_FILES = xbox_live.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


