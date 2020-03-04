include(ign_sismologia.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = ign_sismologia.h

SOURCES = ign_sismologia.cpp

TARGET = $$qtLibraryTarget(ign_sismologia)

DESTDIR = ../../plugins

EXAMPLE_FILES = ign_sismologia.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


