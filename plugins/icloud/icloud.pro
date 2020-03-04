include(icloud.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = icloud.h

SOURCES = icloud.cpp

TARGET = $$qtLibraryTarget(icloud)

DESTDIR = ../../plugins

EXAMPLE_FILES = icloud.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


