include(whois.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = whois.h

SOURCES = whois.cpp

TARGET = $$qtLibraryTarget(whois)

DESTDIR = ../../plugins

EXAMPLE_FILES = whois.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


