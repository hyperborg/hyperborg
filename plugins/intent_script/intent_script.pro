include(intent_script.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = intent_script.h

SOURCES = intent_script.cpp

TARGET = $$qtLibraryTarget(intent_script)

DESTDIR = ../../plugins

EXAMPLE_FILES = intent_script.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


