include(twilio_sms.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = twilio_sms.h

SOURCES = twilio_sms.cpp

TARGET = $$qtLibraryTarget(twilio_sms)

DESTDIR = ../../plugins

EXAMPLE_FILES = twilio_sms.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


