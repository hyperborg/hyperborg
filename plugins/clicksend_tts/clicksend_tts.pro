include(clicksend_tts.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = clicksend_tts.h

SOURCES = clicksend_tts.cpp

TARGET = $$qtLibraryTarget(clicksend_tts)

DESTDIR = ../../plugins

EXAMPLE_FILES = clicksend_tts.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


