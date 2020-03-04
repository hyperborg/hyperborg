include(octoprint.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = octoprint.h

SOURCES = octoprint.cpp

TARGET = $$qtLibraryTarget(octoprint)

DESTDIR = ../../plugins

EXAMPLE_FILES = octoprint.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


