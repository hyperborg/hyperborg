include(route53.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = route53.h

SOURCES = route53.cpp

TARGET = $$qtLibraryTarget(route53)

DESTDIR = ../../plugins

EXAMPLE_FILES = route53.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


