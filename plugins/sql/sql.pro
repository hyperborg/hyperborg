include(sql.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = sql.h

SOURCES = sql.cpp

TARGET = $$qtLibraryTarget(sql)

DESTDIR = ../../plugins

EXAMPLE_FILES = sql.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


