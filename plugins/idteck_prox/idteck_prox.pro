include(idteck_prox.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = idteck_prox.h

SOURCES = idteck_prox.cpp

TARGET = $$qtLibraryTarget(idteck_prox)

DESTDIR = ../../plugins

EXAMPLE_FILES = idteck_prox.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


