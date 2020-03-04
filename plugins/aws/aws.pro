include(aws.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = aws.h

SOURCES = aws.cpp

TARGET = $$qtLibraryTarget(aws)

DESTDIR = ../../plugins

EXAMPLE_FILES = aws.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


