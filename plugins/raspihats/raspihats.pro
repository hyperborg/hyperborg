include(raspihats.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = raspihats.h

SOURCES = raspihats.cpp

TARGET = $$qtLibraryTarget(raspihats)

DESTDIR = ../../plugins

EXAMPLE_FILES = raspihats.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


