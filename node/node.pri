HEADERS += nodecore.h \
	   ../common/hyplugin.h \
	   ../common/common.h \
	   ../common/hsettings.h \
	   ../common/hud.h\
	   ../common/qgraphicsgloweffect.h\
	   beacon.h \
	   basepanel.h \
	   pluginslot.h \
	   coreserver.h \
	   unicore.h \
	   coresocket.h

	
SOURCES +=  main.cpp \
	    nodecore.cpp \
	    ../common/hyplugin.cpp \
	    ../common/hsettings.cpp \
	    ../common/hud.cpp \
	    ../common/qgraphicsgloweffect.cpp \
	    coreserver.cpp \
	    beacon.cpp \
	    basepanel.cpp \
	    pluginslot.cpp \
	    unicore.cpp \
	    coresocket.cpp

FORMS+=	    basepanel.ui \

TRANSLATIONS+=

RESOURCES+=  basepanel.qrc
