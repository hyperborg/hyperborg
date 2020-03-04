include(simplisafe.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = simplisafe.h

SOURCES = simplisafe.cpp

TARGET = $$qtLibraryTarget(simplisafe)

DESTDIR = ../../plugins

EXAMPLE_FILES = simplisafe.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


