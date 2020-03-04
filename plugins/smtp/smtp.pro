include(smtp.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = smtp.h

SOURCES = smtp.cpp

TARGET = $$qtLibraryTarget(smtp)

DESTDIR = ../../plugins

EXAMPLE_FILES = smtp.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


