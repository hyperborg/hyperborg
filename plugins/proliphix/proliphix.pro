include(proliphix.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = proliphix.h

SOURCES = proliphix.cpp

TARGET = $$qtLibraryTarget(proliphix)

DESTDIR = ../../plugins

EXAMPLE_FILES = proliphix.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


