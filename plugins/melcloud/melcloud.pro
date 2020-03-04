include(melcloud.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = melcloud.h

SOURCES = melcloud.cpp

TARGET = $$qtLibraryTarget(melcloud)

DESTDIR = ../../plugins

EXAMPLE_FILES = melcloud.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


