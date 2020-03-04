include(gpmdp.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = gpmdp.h

SOURCES = gpmdp.cpp

TARGET = $$qtLibraryTarget(gpmdp)

DESTDIR = ../../plugins

EXAMPLE_FILES = gpmdp.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


