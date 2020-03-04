include(lockitron.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = lockitron.h

SOURCES = lockitron.cpp

TARGET = $$qtLibraryTarget(lockitron)

DESTDIR = ../../plugins

EXAMPLE_FILES = lockitron.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


