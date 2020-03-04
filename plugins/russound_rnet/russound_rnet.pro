include(russound_rnet.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = russound_rnet.h

SOURCES = russound_rnet.cpp

TARGET = $$qtLibraryTarget(russound_rnet)

DESTDIR = ../../plugins

EXAMPLE_FILES = russound_rnet.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


