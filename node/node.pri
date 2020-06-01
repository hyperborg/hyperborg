HEADERS += nodecore.h \
	   ../common/hyplugin.h \
	   ../common/common.h \
	   ../common/hsettings.h \
	   hud.h\
	   hudlabel.h \
	   ../common/qgraphicsgloweffect.h\
	   beacon.h \
	   basepanel.h \
	   pluginslot.h \
	   coreserver.h \
	   unicore.h \
	   coresocket.h \
	   version.h

	
SOURCES +=  main.cpp \
	    nodecore.cpp \
	    ../common/hyplugin.cpp \
	    ../common/hsettings.cpp \
	    hud.cpp \
	    hudlabel.cpp \
	    ../common/qgraphicsgloweffect.cpp \
	    coreserver.cpp \
	    beacon.cpp \
	    basepanel.cpp \
	    pluginslot.cpp \
	    unicore.cpp \
	    coresocket.cpp

FORMS+=	    basepanel.ui \
	    hud.ui	\
	    hudlabel.ui \

TRANSLATIONS+=

RESOURCES+=  basepanel.qrc
