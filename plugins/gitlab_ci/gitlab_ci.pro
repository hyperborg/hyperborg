include(gitlab_ci.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = gitlab_ci.h

SOURCES = gitlab_ci.cpp

TARGET = $$qtLibraryTarget(gitlab_ci)

DESTDIR = ../../plugins

EXAMPLE_FILES = gitlab_ci.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


