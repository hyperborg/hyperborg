include(prometheus.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = prometheus.h

SOURCES = prometheus.cpp

TARGET = $$qtLibraryTarget(prometheus)

DESTDIR = ../../plugins

EXAMPLE_FILES = prometheus.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


