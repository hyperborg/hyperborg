include(teksavvy.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = teksavvy.h

SOURCES = teksavvy.cpp

TARGET = $$qtLibraryTarget(teksavvy)

DESTDIR = ../../plugins

EXAMPLE_FILES = teksavvy.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


