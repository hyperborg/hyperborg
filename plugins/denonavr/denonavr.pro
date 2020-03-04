include(denonavr.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = denonavr.h

SOURCES = denonavr.cpp

TARGET = $$qtLibraryTarget(denonavr)

DESTDIR = ../../plugins

EXAMPLE_FILES = denonavr.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


