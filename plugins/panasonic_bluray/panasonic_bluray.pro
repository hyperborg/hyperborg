include(panasonic_bluray.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = panasonic_bluray.h

SOURCES = panasonic_bluray.cpp

TARGET = $$qtLibraryTarget(panasonic_bluray)

DESTDIR = ../../plugins

EXAMPLE_FILES = panasonic_bluray.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


