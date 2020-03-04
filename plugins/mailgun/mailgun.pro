include(mailgun.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = mailgun.h

SOURCES = mailgun.cpp

TARGET = $$qtLibraryTarget(mailgun)

DESTDIR = ../../plugins

EXAMPLE_FILES = mailgun.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


