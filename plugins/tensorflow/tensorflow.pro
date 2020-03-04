include(tensorflow.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = tensorflow.h

SOURCES = tensorflow.cpp

TARGET = $$qtLibraryTarget(tensorflow)

DESTDIR = ../../plugins

EXAMPLE_FILES = tensorflow.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


