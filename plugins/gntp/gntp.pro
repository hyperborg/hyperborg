include(gntp.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = gntp.h

SOURCES = gntp.cpp

TARGET = $$qtLibraryTarget(gntp)

DESTDIR = ../../plugins

EXAMPLE_FILES = gntp.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


