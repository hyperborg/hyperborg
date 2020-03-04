include(eq3btsmart.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = eq3btsmart.h

SOURCES = eq3btsmart.cpp

TARGET = $$qtLibraryTarget(eq3btsmart)

DESTDIR = ../../plugins

EXAMPLE_FILES = eq3btsmart.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


