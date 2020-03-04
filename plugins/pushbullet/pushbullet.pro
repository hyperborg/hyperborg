include(pushbullet.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = pushbullet.h

SOURCES = pushbullet.cpp

TARGET = $$qtLibraryTarget(pushbullet)

DESTDIR = ../../plugins

EXAMPLE_FILES = pushbullet.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


