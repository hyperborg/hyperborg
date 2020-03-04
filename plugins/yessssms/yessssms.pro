include(yessssms.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = yessssms.h

SOURCES = yessssms.cpp

TARGET = $$qtLibraryTarget(yessssms)

DESTDIR = ../../plugins

EXAMPLE_FILES = yessssms.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


