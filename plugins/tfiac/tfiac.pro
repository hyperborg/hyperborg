include(tfiac.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = tfiac.h

SOURCES = tfiac.cpp

TARGET = $$qtLibraryTarget(tfiac)

DESTDIR = ../../plugins

EXAMPLE_FILES = tfiac.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


