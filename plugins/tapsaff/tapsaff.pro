include(tapsaff.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = tapsaff.h

SOURCES = tapsaff.cpp

TARGET = $$qtLibraryTarget(tapsaff)

DESTDIR = ../../plugins

EXAMPLE_FILES = tapsaff.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


