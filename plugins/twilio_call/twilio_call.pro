include(twilio_call.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = twilio_call.h

SOURCES = twilio_call.cpp

TARGET = $$qtLibraryTarget(twilio_call)

DESTDIR = ../../plugins

EXAMPLE_FILES = twilio_call.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


