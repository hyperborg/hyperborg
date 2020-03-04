include(travisci.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = travisci.h

SOURCES = travisci.cpp

TARGET = $$qtLibraryTarget(travisci)

DESTDIR = ../../plugins

EXAMPLE_FILES = travisci.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


