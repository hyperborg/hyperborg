include(python_script.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = python_script.h

SOURCES = python_script.cpp

TARGET = $$qtLibraryTarget(python_script)

DESTDIR = ../../plugins

EXAMPLE_FILES = python_script.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


