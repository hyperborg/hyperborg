include(heishamon.pri)

QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-parameter
contains(QT_CONFIG, c++11): CONFIG+= c++11

TEMPLATE=lib
CONFIG+=plugin
QT+= network

INCLUDEPATH +=../../common
TARGET = $$qtLibraryTarget(heishamon)
DESTDIR = ../../plugins
EXAMPLE_FILES = heishamon.json

linux {
MOC_DIR=../../.build/.moc/$$TARGET
OBJECTS_DIR=../../.build/.objs/$$TARGET
RCC_DIR=../../.build/.rcc/$$TARGET
UI_DIR=../../.build/.uic/$$TARGET
}

raspberry {
    DEFINES +=PLATFORM_RPI
}
