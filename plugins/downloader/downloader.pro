include(downloader.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = downloader.h

SOURCES = downloader.cpp

TARGET = $$qtLibraryTarget(downloader)

DESTDIR = ../../plugins

EXAMPLE_FILES = downloader.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


