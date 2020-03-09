include(onewire.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common
TARGET = $$qtLibraryTarget(onewire)
DESTDIR = ../../plugins
EXAMPLE_FILES = onewire.json

linux {
    MOC_DIR=../../.build/.moc
    OBJECTS_DIR=../../.build/.objs
    RCC_DIR=../../.build/.rcc
    UI_DIR=../../.build/.uic
}




