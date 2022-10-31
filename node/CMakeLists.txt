cmake_minimum_required(VERSION 3.22)

project(hynode LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(NOT DEFINED INSTALL_EXAMPLESDIR)
  set(INSTALL_EXAMPLESDIR "examples")
endif()

set(INSTALL_EXAMPLEDIR "${INSTALL_EXAMPLESDIR}")

find_package(Qt6 COMPONENTS Charts)
find_package(Qt6 COMPONENTS Core)
find_package(Qt6 COMPONENTS DBus)
find_package(Qt6 COMPONENTS Gui)
find_package(Qt6 COMPONENTS Network)
find_package(Qt6 COMPONENTS WebSockets)
find_package(Qt6 COMPONENTS Widgets)
find_package(Qt6 COMPONENTS Xml)
find_package(Qt6 COMPONENTS Qml)
find_package(Qt6 COMPONENTS Quick)

qt_add_executable(hynode WIN32 MACOSX_BUNDLE
    ../common/buffer.cpp ../common/buffer.h
    ../common/common.h
    ../common/hyobject.cpp ../common/hyobject.h
    ../common/hyplugin.cpp ../common/hyplugin.h
    ../common/microcode.cpp ../common/microcode.h
    ../common/qgraphicsgloweffect.cpp ../common/qgraphicsgloweffect.h
    ../common/hfs.h ../common/hfs.cpp
    ../common/hfsitem.h ../common/hfsitem.cpp
    ../common/colorrange.h
    beacon.cpp beacon.h
    coreserver.cpp coreserver.h
    hud.h hud.cpp
    main.cpp
    nodecore.cpp nodecore.h
    pluginslot.cpp pluginslot.h
    slotter.cpp slotter.h
    unicore.cpp unicore.h
    vcpu.cpp vcpu.h  
    hyperborg.qrc

    hud/hudbutton.h hud/hudbutton.cpp 
    hud/hudcalendar.h hud/hudcalendar.cpp
    hud/hudclock.h hud/hudclock.cpp
    hud/hudelement.h hud/hudelement.cpp
    hud/hudeventlist.h hud/hudeventlist.cpp 
    hud/hudfactory.h hud/hudfactory.cpp 
    hud/hudgarbage.h hud/hudgarbage.cpp 
    hud/hudgauge.h hud/hudgauge.cpp 
    hud/hudhfstree.h hud/hudhfstree.cpp
    hud/hudlibrary.h hud/hudlibrary.cpp
    hud/hudnavigator.h hud/hudnavigator.cpp
    hud/hudpowergrid.h hud/hudpowergrid.cpp 
    hud/hudscreen.h hud/hudscreen.cpp 
    hud/hudshoppinglist.h hud/hudshoppinglist.cpp 
    hud/hudtimetable.h hud/hudtimetable.cpp 
    hud/hudtodolist.h hud/hudtodolist.cpp 
    hud/hudweather.h hud/hudweather.cpp 
)


target_include_directories(hynode PUBLIC
    .
    ../common
    ../common/entity
    hud
)

target_link_libraries(hynode PUBLIC
    Qt::Charts
    Qt::Core
    Qt::Gui
    Qt::Network
    Qt::WebSockets
    Qt::Widgets
    Qt::Xml
    Qt::Qml
    Qt::Quick
)

if(LINUX)
    add_compile_definitions(PF_LINUX)
    target_include_directories(hynode PUBLIC
        ../plugins/paradox
    )

    target_link_libraries(hynode PUBLIC
        Qt::SerialPort
        Qt::Sql
    )
endif()

if(EMSCRIPTEN)
    add_compile_definitions(PF_EMSCRIPTEN)
    target_compile_definitions(hynode PUBLIC
        WASM
    )

endif()

install(TARGETS hynode
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)
