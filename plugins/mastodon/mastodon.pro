include(mastodon.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = mastodon.h

SOURCES = mastodon.cpp

TARGET = $$qtLibraryTarget(mastodon)

DESTDIR = ../../plugins

EXAMPLE_FILES = mastodon.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


