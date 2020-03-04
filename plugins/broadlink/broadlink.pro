include(broadlink.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = broadlink.h

SOURCES = broadlink.cpp

TARGET = $$qtLibraryTarget(broadlink)

DESTDIR = ../../plugins

EXAMPLE_FILES = broadlink.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


