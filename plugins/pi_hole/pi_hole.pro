include(pi_hole.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = pi_hole.h

SOURCES = pi_hole.cpp

TARGET = $$qtLibraryTarget(pi_hole)

DESTDIR = ../../plugins

EXAMPLE_FILES = pi_hole.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


