include(tellstick.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = tellstick.h

SOURCES = tellstick.cpp

TARGET = $$qtLibraryTarget(tellstick)

DESTDIR = ../../plugins

EXAMPLE_FILES = tellstick.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


