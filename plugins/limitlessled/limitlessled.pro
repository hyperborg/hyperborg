include(limitlessled.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = limitlessled.h

SOURCES = limitlessled.cpp

TARGET = $$qtLibraryTarget(limitlessled)

DESTDIR = ../../plugins

EXAMPLE_FILES = limitlessled.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


