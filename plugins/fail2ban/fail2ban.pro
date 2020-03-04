include(fail2ban.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = fail2ban.h

SOURCES = fail2ban.cpp

TARGET = $$qtLibraryTarget(fail2ban)

DESTDIR = ../../plugins

EXAMPLE_FILES = fail2ban.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


