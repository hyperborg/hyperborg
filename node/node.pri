HEADERS += nodecore.h \
	   ../common/hyplugin.h \
	   ../common/common.h \
	   ../common/hsettings.h \
	   ../common/buffer.h \
	   ../common/microcode.h \
	   ../common/entity.h \
	   codeeditor.h \
	   hud.h\
	   hudelements.h \
	   hudlabel.h \
	   ../common/qgraphicsgloweffect.h\
	   beacon.h \
	   basepanel.h \
	   slotter.h \
	   pluginslot.h \
	   coreserver.h \
	   unicore.h \
	   version.h

	
SOURCES +=  main.cpp \
	    nodecore.cpp \
	    ../common/hyplugin.cpp \
	    ../common/hsettings.cpp \
	    ../common/buffer.cpp \
	    ../common/microcode.cpp \
	    ../common/entity.cpp \
            codeeditor.cpp \
	    hud.cpp \
	    hudlabel.cpp \
#	    minicore.cpp \
	    hudelements.cpp \
	    ../common/qgraphicsgloweffect.cpp \
	    coreserver.cpp \
	    beacon.cpp \
	    basepanel.cpp \
	    pluginslot.cpp \
	    unicore.cpp \
	    slotter.cpp

FORMS+=	    basepanel.ui \
	    hud.ui	\
	    hudlabel.ui \
	    codeeditor.ui \


TRANSLATIONS+=

RESOURCES+=  basepanel.qrc

linux {
HEADERS += 	minicore.h \
		../plugins/paradox/paradox.h \
		../plugins/hyi2c/hyi2c.h \

SOURCES +=	minicore.cpp \
		../plugins/paradox/paradox.cpp \
		../plugins/hyi2c/hyi2c.cpp
}

linux-rasp-pi4-v3d-g++{

HEADERS += 	minicore.h \
		../plugins/paradox/paradox.h \
		../plugins/hyi2c/hyi2c.h \

SOURCES +=	minicore.cpp \
		../plugins/paradox/paradox.cpp \
		../plugins/hyi2c/hyi2c.cpp


}

