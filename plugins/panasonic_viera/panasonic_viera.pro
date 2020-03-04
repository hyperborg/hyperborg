include(panasonic_viera.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = panasonic_viera.h

SOURCES = panasonic_viera.cpp

TARGET = $$qtLibraryTarget(panasonic_viera)

DESTDIR = ../../plugins

EXAMPLE_FILES = panasonic_viera.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


