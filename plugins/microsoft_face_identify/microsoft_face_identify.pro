include(microsoft_face_identify.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = microsoft_face_identify.h

SOURCES = microsoft_face_identify.cpp

TARGET = $$qtLibraryTarget(microsoft_face_identify)

DESTDIR = ../../plugins

EXAMPLE_FILES = microsoft_face_identify.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


