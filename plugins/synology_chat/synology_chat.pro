include(synology_chat.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = synology_chat.h

SOURCES = synology_chat.cpp

TARGET = $$qtLibraryTarget(synology_chat)

DESTDIR = ../../plugins

EXAMPLE_FILES = synology_chat.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


