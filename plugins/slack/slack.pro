include(slack.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = slack.h

SOURCES = slack.cpp

TARGET = $$qtLibraryTarget(slack)

DESTDIR = ../../plugins

EXAMPLE_FILES = slack.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


