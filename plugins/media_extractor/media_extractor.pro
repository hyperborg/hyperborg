include(media_extractor.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = media_extractor.h

SOURCES = media_extractor.cpp

TARGET = $$qtLibraryTarget(media_extractor)

DESTDIR = ../../plugins

EXAMPLE_FILES = media_extractor.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


