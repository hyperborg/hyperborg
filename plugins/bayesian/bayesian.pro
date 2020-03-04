include(bayesian.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = bayesian.h

SOURCES = bayesian.cpp

TARGET = $$qtLibraryTarget(bayesian)

DESTDIR = ../../plugins

EXAMPLE_FILES = bayesian.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


