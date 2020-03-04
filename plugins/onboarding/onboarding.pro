include(onboarding.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = onboarding.h

SOURCES = onboarding.cpp

TARGET = $$qtLibraryTarget(onboarding)

DESTDIR = ../../plugins

EXAMPLE_FILES = onboarding.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


