include(starline.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = starline.h

SOURCES = starline.cpp

TARGET = $$qtLibraryTarget(starline)

DESTDIR = ../../plugins

EXAMPLE_FILES = starline.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


