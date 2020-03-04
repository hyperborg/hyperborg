include(tautulli.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = tautulli.h

SOURCES = tautulli.cpp

TARGET = $$qtLibraryTarget(tautulli)

DESTDIR = ../../plugins

EXAMPLE_FILES = tautulli.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


