include(qrcode.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = qrcode.h

SOURCES = qrcode.cpp

TARGET = $$qtLibraryTarget(qrcode)

DESTDIR = ../../plugins

EXAMPLE_FILES = qrcode.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


