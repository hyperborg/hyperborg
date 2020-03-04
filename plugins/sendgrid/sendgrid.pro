include(sendgrid.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = sendgrid.h

SOURCES = sendgrid.cpp

TARGET = $$qtLibraryTarget(sendgrid)

DESTDIR = ../../plugins

EXAMPLE_FILES = sendgrid.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


