include(fitbit.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = fitbit.h

SOURCES = fitbit.cpp

TARGET = $$qtLibraryTarget(fitbit)

DESTDIR = ../../plugins

EXAMPLE_FILES = fitbit.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


