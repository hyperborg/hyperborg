include(xmpp.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = xmpp.h

SOURCES = xmpp.cpp

TARGET = $$qtLibraryTarget(xmpp)

DESTDIR = ../../plugins

EXAMPLE_FILES = xmpp.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


