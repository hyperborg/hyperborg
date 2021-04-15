HEADERS +=  nodecore.h \
            codeeditor.h \
            hud.h \
	    hudscene.h \
            hudelements.h \
            hudlabel.h \
            beacon.h \
            basepanel.h \
            slotter.h \
            pluginslot.h \
            coreserver.h \
            unicore.h \
            ../common/hyplugin.h \
            ../common/common.h \
            ../common/hsettings.h \
            ../common/buffer.h \
            ../common/microcode.h \
            ../common/qgraphicsgloweffect.h 

SOURCES +=  main.cpp \
            nodecore.cpp \
            codeeditor.cpp \
            hud.cpp \
	    hudscene.cpp \
            hudlabel.cpp \
            hudelements.cpp \
            coreserver.cpp \
            beacon.cpp \
            basepanel.cpp \
            pluginslot.cpp \
            unicore.cpp \
            slotter.cpp \
            ../common/hyplugin.cpp \
            ../common/hsettings.cpp \
            ../common/buffer.cpp \
            ../common/microcode.cpp \
            ../common/qgraphicsgloweffect.cpp 

FORMS+=	    basepanel.ui \
            hud.ui \
            hudlabel.ui \
            codeeditor.ui \

TRANSLATIONS+=

RESOURCES+=  basepanel.qrc \
	     hud.qrc

linux {
}

linux-rasp-pi4-v3d-g++{

}

