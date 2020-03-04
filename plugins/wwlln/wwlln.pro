include(wwlln.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = wwlln.h

SOURCES = wwlln.cpp

TARGET = $$qtLibraryTarget(wwlln)

DESTDIR = ../../plugins

EXAMPLE_FILES = wwlln.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


