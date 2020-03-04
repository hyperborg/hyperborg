include(local_file.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = local_file.h

SOURCES = local_file.cpp

TARGET = $$qtLibraryTarget(local_file)

DESTDIR = ../../plugins

EXAMPLE_FILES = local_file.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


