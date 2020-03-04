include(zhong_hong.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = zhong_hong.h

SOURCES = zhong_hong.cpp

TARGET = $$qtLibraryTarget(zhong_hong)

DESTDIR = ../../plugins

EXAMPLE_FILES = zhong_hong.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


