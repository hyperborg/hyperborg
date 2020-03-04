include(viaggiatreno.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = viaggiatreno.h

SOURCES = viaggiatreno.cpp

TARGET = $$qtLibraryTarget(viaggiatreno)

DESTDIR = ../../plugins

EXAMPLE_FILES = viaggiatreno.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


