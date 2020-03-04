include(command_line.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = command_line.h

SOURCES = command_line.cpp

TARGET = $$qtLibraryTarget(command_line)

DESTDIR = ../../plugins

EXAMPLE_FILES = command_line.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


