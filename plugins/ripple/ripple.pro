include(ripple.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = ripple.h

SOURCES = ripple.cpp

TARGET = $$qtLibraryTarget(ripple)

DESTDIR = ../../plugins

EXAMPLE_FILES = ripple.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


