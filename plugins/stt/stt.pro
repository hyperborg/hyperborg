include(stt.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = stt.h

SOURCES = stt.cpp

TARGET = $$qtLibraryTarget(stt)

DESTDIR = ../../plugins

EXAMPLE_FILES = stt.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


