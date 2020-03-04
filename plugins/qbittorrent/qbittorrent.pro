include(qbittorrent.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = qbittorrent.h

SOURCES = qbittorrent.cpp

TARGET = $$qtLibraryTarget(qbittorrent)

DESTDIR = ../../plugins

EXAMPLE_FILES = qbittorrent.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


