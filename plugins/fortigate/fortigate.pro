include(fortigate.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = fortigate.h

SOURCES = fortigate.cpp

TARGET = $$qtLibraryTarget(fortigate)

DESTDIR = ../../plugins

EXAMPLE_FILES = fortigate.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


