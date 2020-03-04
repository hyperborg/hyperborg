include(prezzibenzina.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = prezzibenzina.h

SOURCES = prezzibenzina.cpp

TARGET = $$qtLibraryTarget(prezzibenzina)

DESTDIR = ../../plugins

EXAMPLE_FILES = prezzibenzina.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


