include(yeelightsunflower.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = yeelightsunflower.h

SOURCES = yeelightsunflower.cpp

TARGET = $$qtLibraryTarget(yeelightsunflower)

DESTDIR = ../../plugins

EXAMPLE_FILES = yeelightsunflower.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


