HEADERS += nodecore.h \
	   ../common/hyplugin.h \
	   ../common/common.h \
	   beacon.h \
	   coreserver.h \
	   basepanel.h


SOURCES +=  main.cpp \
	    nodecore.cpp \
	    ../common/hyplugin.cpp \
	    coreserver.cpp \
	    beacon.cpp \
	    basepanel.cpp

FORMS+=	    basepanel.ui \

TRANSLATIONS+=

RESOURCES+=  basepanel.qrc
