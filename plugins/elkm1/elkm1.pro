include(elkm1.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = elkm1.h

SOURCES = elkm1.cpp

TARGET = $$qtLibraryTarget(elkm1)

DESTDIR = ../../plugins

EXAMPLE_FILES = elkm1.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


