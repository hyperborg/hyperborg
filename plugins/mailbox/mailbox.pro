include(mailbox.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = mailbox.h

SOURCES = mailbox.cpp

TARGET = $$qtLibraryTarget(mailbox)

DESTDIR = ../../plugins

EXAMPLE_FILES = mailbox.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


