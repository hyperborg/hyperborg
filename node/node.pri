HEADERS += nodecore.h \
	   ../common/hyplugin.h \
	   ../common/common.h \
	   ../common/hsettings.h \
	   ../common/buffer.h \
	   ../common/microcode.h \
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
	    hud.cpp \
	    hudlabel.cpp \
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

TRANSLATIONS+=

RESOURCES+=  basepanel.qrc
