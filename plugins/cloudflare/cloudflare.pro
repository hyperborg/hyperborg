include(cloudflare.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = cloudflare.h

SOURCES = cloudflare.cpp

TARGET = $$qtLibraryTarget(cloudflare)

DESTDIR = ../../plugins

EXAMPLE_FILES = cloudflare.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


