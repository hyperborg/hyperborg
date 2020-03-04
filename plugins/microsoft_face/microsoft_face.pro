include(microsoft_face.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = microsoft_face.h

SOURCES = microsoft_face.cpp

TARGET = $$qtLibraryTarget(microsoft_face)

DESTDIR = ../../plugins

EXAMPLE_FILES = microsoft_face.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


