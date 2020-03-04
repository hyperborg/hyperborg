include(pushover.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = pushover.h

SOURCES = pushover.cpp

TARGET = $$qtLibraryTarget(pushover)

DESTDIR = ../../plugins

EXAMPLE_FILES = pushover.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


