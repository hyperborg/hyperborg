include(modem_callerid.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = modem_callerid.h

SOURCES = modem_callerid.cpp

TARGET = $$qtLibraryTarget(modem_callerid)

DESTDIR = ../../plugins

EXAMPLE_FILES = modem_callerid.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


