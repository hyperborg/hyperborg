include(imap.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = imap.h

SOURCES = imap.cpp

TARGET = $$qtLibraryTarget(imap)

DESTDIR = ../../plugins

EXAMPLE_FILES = imap.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


