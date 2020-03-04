include(voicerss.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = voicerss.h

SOURCES = voicerss.cpp

TARGET = $$qtLibraryTarget(voicerss)

DESTDIR = ../../plugins

EXAMPLE_FILES = voicerss.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


