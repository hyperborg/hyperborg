include(watson_tts.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = watson_tts.h

SOURCES = watson_tts.cpp

TARGET = $$qtLibraryTarget(watson_tts)

DESTDIR = ../../plugins

EXAMPLE_FILES = watson_tts.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


