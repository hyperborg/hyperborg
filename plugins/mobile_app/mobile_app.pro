include(mobile_app.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = mobile_app.h

SOURCES = mobile_app.cpp

TARGET = $$qtLibraryTarget(mobile_app)

DESTDIR = ../../plugins

EXAMPLE_FILES = mobile_app.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


