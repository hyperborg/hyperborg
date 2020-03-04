include(nuheat.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = nuheat.h

SOURCES = nuheat.cpp

TARGET = $$qtLibraryTarget(nuheat)

DESTDIR = ../../plugins

EXAMPLE_FILES = nuheat.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


