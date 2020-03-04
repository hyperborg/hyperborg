include(tellduslive.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = tellduslive.h

SOURCES = tellduslive.cpp

TARGET = $$qtLibraryTarget(tellduslive)

DESTDIR = ../../plugins

EXAMPLE_FILES = tellduslive.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


