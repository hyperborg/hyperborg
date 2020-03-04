include(aurora_abb_powerone.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = aurora_abb_powerone.h

SOURCES = aurora_abb_powerone.cpp

TARGET = $$qtLibraryTarget(aurora_abb_powerone)

DESTDIR = ../../plugins

EXAMPLE_FILES = aurora_abb_powerone.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


