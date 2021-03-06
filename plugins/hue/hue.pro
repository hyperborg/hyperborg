include(hue.pri)

TEMPLATE = lib
CONFIG 	+= plugin
QT 	    += network

INCLUDEPATH    += ../../common
TARGET          = $$qtLibraryTarget(hue)
DESTDIR         = ../../plugins
EXAMPLE_FILES   = hue.json
MOC_DIR         = ../../.build/.moc
OBJECTS_DIR     = ../../.build/.objs
RCC_DIR         = ../../.build/.rcc
UI_DIR          = ../../.build/.uic

emscripten {
    DEFINES+=wasm
}

linux {
    DEFINES+=linux
}

