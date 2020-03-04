include(telegram_bot.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = telegram_bot.h

SOURCES = telegram_bot.cpp

TARGET = $$qtLibraryTarget(telegram_bot)

DESTDIR = ../../plugins

EXAMPLE_FILES = telegram_bot.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


