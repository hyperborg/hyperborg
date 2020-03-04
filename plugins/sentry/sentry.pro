include(sentry.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = sentry.h

SOURCES = sentry.cpp

TARGET = $$qtLibraryTarget(sentry)

DESTDIR = ../../plugins

EXAMPLE_FILES = sentry.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


