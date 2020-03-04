include(launch_library.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = launch_library.h

SOURCES = launch_library.cpp

TARGET = $$qtLibraryTarget(launch_library)

DESTDIR = ../../plugins

EXAMPLE_FILES = launch_library.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


