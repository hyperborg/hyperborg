include(switcher_kis.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = switcher_kis.h

SOURCES = switcher_kis.cpp

TARGET = $$qtLibraryTarget(switcher_kis)

DESTDIR = ../../plugins

EXAMPLE_FILES = switcher_kis.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


