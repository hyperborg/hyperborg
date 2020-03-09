HEADERS += nodecore.h \
	   ../common/hyplugin.h \
	   ../common/common.h \
	   beacon.h \
	   coreserver.h \
	   basepanel.h \
	   pluginslot.h


SOURCES +=  main.cpp \
	    nodecore.cpp \
	    ../common/hyplugin.cpp \
	    coreserver.cpp \
	    beacon.cpp \
	    basepanel.cpp \
	    pluginslot.cpp 

FORMS+=	    basepanel.ui \

TRANSLATIONS+=

RESOURCES+=  basepanel.qrc
