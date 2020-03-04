include(hive.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = hive.h

SOURCES = hive.cpp

TARGET = $$qtLibraryTarget(hive)

DESTDIR = ../../plugins

EXAMPLE_FILES = hive.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


