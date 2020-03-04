include(mpchc.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = mpchc.h

SOURCES = mpchc.cpp

TARGET = $$qtLibraryTarget(mpchc)

DESTDIR = ../../plugins

EXAMPLE_FILES = mpchc.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


