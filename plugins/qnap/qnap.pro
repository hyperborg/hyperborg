include(qnap.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = qnap.h

SOURCES = qnap.cpp

TARGET = $$qtLibraryTarget(qnap)

DESTDIR = ../../plugins

EXAMPLE_FILES = qnap.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


