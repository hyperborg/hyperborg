include(sms.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = sms.h

SOURCES = sms.cpp

TARGET = $$qtLibraryTarget(sms)

DESTDIR = ../../plugins

EXAMPLE_FILES = sms.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


