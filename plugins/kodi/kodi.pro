include(kodi.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = kodi.h

SOURCES = kodi.cpp

TARGET = $$qtLibraryTarget(kodi)

DESTDIR = ../../plugins

EXAMPLE_FILES = kodi.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


