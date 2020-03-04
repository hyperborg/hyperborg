include(folder_watcher.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = folder_watcher.h

SOURCES = folder_watcher.cpp

TARGET = $$qtLibraryTarget(folder_watcher)

DESTDIR = ../../plugins

EXAMPLE_FILES = folder_watcher.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


