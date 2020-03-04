include(eight_sleep.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = eight_sleep.h

SOURCES = eight_sleep.cpp

TARGET = $$qtLibraryTarget(eight_sleep)

DESTDIR = ../../plugins

EXAMPLE_FILES = eight_sleep.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


