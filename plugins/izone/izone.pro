include(izone.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = izone.h

SOURCES = izone.cpp

TARGET = $$qtLibraryTarget(izone)

DESTDIR = ../../plugins

EXAMPLE_FILES = izone.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


