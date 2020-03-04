include(dialogflow.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = dialogflow.h

SOURCES = dialogflow.cpp

TARGET = $$qtLibraryTarget(dialogflow)

DESTDIR = ../../plugins

EXAMPLE_FILES = dialogflow.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


