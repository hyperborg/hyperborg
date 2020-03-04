include(sabnzbd.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = sabnzbd.h

SOURCES = sabnzbd.cpp

TARGET = $$qtLibraryTarget(sabnzbd)

DESTDIR = ../../plugins

EXAMPLE_FILES = sabnzbd.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


