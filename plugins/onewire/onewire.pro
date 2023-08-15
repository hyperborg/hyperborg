include(onewire.pri)

TEMPLATE=lib

CONFIG+=plugin
QT+= xml

INCLUDEPATH +=../../common
TARGET = $$qtLibraryTarget(onewire)
DESTDIR = ../../plugins
EXAMPLE_FILES = onewire.json

linux {
    MOC_DIR=../../.build/.moc/$$TARGET
    OBJECTS_DIR=../../.build/.objs/$$TARGET
    RCC_DIR=../../.build/.rcc/$$TARGET
    UI_DIR=../../.build/.uic/$$TARGET
}




