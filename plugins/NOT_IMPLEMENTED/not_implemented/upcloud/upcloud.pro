include(upcloud.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common
TARGET = $$qtLibraryTarget(upcloud)
DESTDIR = ../../plugins
EXAMPLE_FILES = upcloud.json
MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic

emscripten {
    DEFINES+=wasm
}

linux {
    DEFINES+=linux
}

