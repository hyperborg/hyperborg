include(alpha_vantage.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = alpha_vantage.h

SOURCES = alpha_vantage.cpp

TARGET = $$qtLibraryTarget(alpha_vantage)

DESTDIR = ../../plugins

EXAMPLE_FILES = alpha_vantage.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


