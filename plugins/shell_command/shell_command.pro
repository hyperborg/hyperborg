include(shell_command.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = shell_command.h

SOURCES = shell_command.cpp

TARGET = $$qtLibraryTarget(shell_command)

DESTDIR = ../../plugins

EXAMPLE_FILES = shell_command.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


