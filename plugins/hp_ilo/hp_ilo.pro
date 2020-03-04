include(hp_ilo.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = hp_ilo.h

SOURCES = hp_ilo.cpp

TARGET = $$qtLibraryTarget(hp_ilo)

DESTDIR = ../../plugins

EXAMPLE_FILES = hp_ilo.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


