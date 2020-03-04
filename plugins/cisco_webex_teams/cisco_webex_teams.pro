include(cisco_webex_teams.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = cisco_webex_teams.h

SOURCES = cisco_webex_teams.cpp

TARGET = $$qtLibraryTarget(cisco_webex_teams)

DESTDIR = ../../plugins

EXAMPLE_FILES = cisco_webex_teams.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


