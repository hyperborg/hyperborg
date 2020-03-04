include(habitica.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = habitica.h

SOURCES = habitica.cpp

TARGET = $$qtLibraryTarget(habitica)

DESTDIR = ../../plugins

EXAMPLE_FILES = habitica.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


