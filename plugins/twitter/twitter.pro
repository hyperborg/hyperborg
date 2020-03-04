include(twitter.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = twitter.h

SOURCES = twitter.cpp

TARGET = $$qtLibraryTarget(twitter)

DESTDIR = ../../plugins

EXAMPLE_FILES = twitter.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


