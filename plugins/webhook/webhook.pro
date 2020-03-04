include(webhook.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = webhook.h

SOURCES = webhook.cpp

TARGET = $$qtLibraryTarget(webhook)

DESTDIR = ../../plugins

EXAMPLE_FILES = webhook.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


