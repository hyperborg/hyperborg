include(streamlabswater.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = streamlabswater.h

SOURCES = streamlabswater.cpp

TARGET = $$qtLibraryTarget(streamlabswater)

DESTDIR = ../../plugins

EXAMPLE_FILES = streamlabswater.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


