include(vivotek.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = vivotek.h

SOURCES = vivotek.cpp

TARGET = $$qtLibraryTarget(vivotek)

DESTDIR = ../../plugins

EXAMPLE_FILES = vivotek.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


