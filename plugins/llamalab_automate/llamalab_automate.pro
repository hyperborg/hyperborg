include(llamalab_automate.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = llamalab_automate.h

SOURCES = llamalab_automate.cpp

TARGET = $$qtLibraryTarget(llamalab_automate)

DESTDIR = ../../plugins

EXAMPLE_FILES = llamalab_automate.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


