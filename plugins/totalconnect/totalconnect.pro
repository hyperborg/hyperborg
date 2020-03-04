include(totalconnect.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = totalconnect.h

SOURCES = totalconnect.cpp

TARGET = $$qtLibraryTarget(totalconnect)

DESTDIR = ../../plugins

EXAMPLE_FILES = totalconnect.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


