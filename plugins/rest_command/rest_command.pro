include(rest_command.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = rest_command.h

SOURCES = rest_command.cpp

TARGET = $$qtLibraryTarget(rest_command)

DESTDIR = ../../plugins

EXAMPLE_FILES = rest_command.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


