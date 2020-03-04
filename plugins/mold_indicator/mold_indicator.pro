include(mold_indicator.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = mold_indicator.h

SOURCES = mold_indicator.cpp

TARGET = $$qtLibraryTarget(mold_indicator)

DESTDIR = ../../plugins

EXAMPLE_FILES = mold_indicator.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


