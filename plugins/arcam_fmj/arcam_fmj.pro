include(arcam_fmj.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = arcam_fmj.h

SOURCES = arcam_fmj.cpp

TARGET = $$qtLibraryTarget(arcam_fmj)

DESTDIR = ../../plugins

EXAMPLE_FILES = arcam_fmj.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


