include(qvr_pro.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = qvr_pro.h

SOURCES = qvr_pro.cpp

TARGET = $$qtLibraryTarget(qvr_pro)

DESTDIR = ../../plugins

EXAMPLE_FILES = qvr_pro.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


