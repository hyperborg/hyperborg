include(slide.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = slide.h

SOURCES = slide.cpp

TARGET = $$qtLibraryTarget(slide)

DESTDIR = ../../plugins

EXAMPLE_FILES = slide.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


