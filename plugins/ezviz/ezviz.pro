include(ezviz.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = ezviz.h

SOURCES = ezviz.cpp

TARGET = $$qtLibraryTarget(ezviz)

DESTDIR = ../../plugins

EXAMPLE_FILES = ezviz.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


