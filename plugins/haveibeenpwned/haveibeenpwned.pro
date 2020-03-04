include(haveibeenpwned.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = haveibeenpwned.h

SOURCES = haveibeenpwned.cpp

TARGET = $$qtLibraryTarget(haveibeenpwned)

DESTDIR = ../../plugins

EXAMPLE_FILES = haveibeenpwned.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


