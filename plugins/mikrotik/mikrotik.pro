include(mikrotik.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = mikrotik.h

SOURCES = mikrotik.cpp

TARGET = $$qtLibraryTarget(mikrotik)

DESTDIR = ../../plugins

EXAMPLE_FILES = mikrotik.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


