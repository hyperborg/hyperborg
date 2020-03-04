include(versasense.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = versasense.h

SOURCES = versasense.cpp

TARGET = $$qtLibraryTarget(versasense)

DESTDIR = ../../plugins

EXAMPLE_FILES = versasense.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


