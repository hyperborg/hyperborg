HEADERS +=  nodecore.h \
            hud.h \
	    hudfactory.h \
            beacon.h \
            slotter.h \
            pluginslot.h \
            coreserver.h \
            unicore.h \
            ../common/hyplugin.h \
            ../common/hyobject.h \
            ../common/common.h \
            ../common/buffer.h \
	    ../common/hfs.h \
            ../common/microcode.h \
            ../common/qgraphicsgloweffect.h \


SOURCES +=  main.cpp \
            nodecore.cpp \
            hud.cpp \
	    hudfactory.cpp \
            coreserver.cpp \
            beacon.cpp \
            pluginslot.cpp \
            unicore.cpp \
            slotter.cpp \
            ../common/hyplugin.cpp \
            ../common/hyobject.cpp \
            ../common/buffer.cpp \
	    ../common/hfs.cpp \
            ../common/microcode.cpp \
            ../common/qgraphicsgloweffect.cpp \

FORMS+=	   

TRANSLATIONS+=

RESOURCES+= 

linux {
}

linux-rasp-pi4-v3d-g++{

}

