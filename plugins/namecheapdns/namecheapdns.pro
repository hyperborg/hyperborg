include(namecheapdns.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = namecheapdns.h

SOURCES = namecheapdns.cpp

TARGET = $$qtLibraryTarget(namecheapdns)

DESTDIR = ../../plugins

EXAMPLE_FILES = namecheapdns.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


