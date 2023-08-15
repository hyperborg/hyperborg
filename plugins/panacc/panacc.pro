include(panacc.pri)

TEMPLATE=lib
CONFIG+=plugin
QT+=

INCLUDEPATH +=../../common

TARGET = $$qtLibraryTarget(panacc)

DESTDIR = ../../plugins

EXAMPLE_FILES = panacc.json

MOC_DIR=../../.build/.moc/$$TARGET
OBJECTS_DIR=../../.build/.objs/$$TARGET
RCC_DIR=../../.build/.rcc/$$TARGET
UI_DIR=../../.build/.uic/$$TARGET

