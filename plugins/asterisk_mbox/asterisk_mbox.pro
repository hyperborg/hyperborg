include(asterisk_mbox.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = asterisk_mbox.h

SOURCES = asterisk_mbox.cpp

TARGET = $$qtLibraryTarget(asterisk_mbox)

DESTDIR = ../../plugins

EXAMPLE_FILES = asterisk_mbox.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


