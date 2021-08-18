include(ws3500.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= network

INCLUDEPATH +=../../common

TARGET = $$qtLibraryTarget(ws3500)

DESTDIR = ../../plugins

EXAMPLE_FILES = ws3500.json

MOC_DIR=../../.build/.moc/$$TARGET
OBJECTS_DIR=../../.build/.objs/$$TARGET
RCC_DIR=../../.build/.rcc/$$TARGET
UI_DIR=../../.build/.uic/$$TARGET

