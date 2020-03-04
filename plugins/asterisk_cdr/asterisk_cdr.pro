include(asterisk_cdr.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = asterisk_cdr.h

SOURCES = asterisk_cdr.cpp

TARGET = $$qtLibraryTarget(asterisk_cdr)

DESTDIR = ../../plugins

EXAMPLE_FILES = asterisk_cdr.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


