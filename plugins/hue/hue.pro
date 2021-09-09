include(hue.pri)

TEMPLATE = lib
CONFIG 	+= plugin
QT 	    += network

INCLUDEPATH    += ../../common
TARGET          = $$qtLibraryTarget(hue)
DESTDIR         = ../../plugins
EXAMPLE_FILES   = hue.json

MOC_DIR         = ../../.build/.moc/$$TARGET
OBJECTS_DIR     = ../../.build/.objs/$$TARGET
RCC_DIR         = ../../.build/.rcc/$$TARGET
UI_DIR          = ../../.build/.uic/$$TARGET

emscripten {
    DEFINES+=wasm
}

linux {
    DEFINES+=linux
}

