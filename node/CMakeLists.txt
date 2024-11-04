cmake_minimum_required(VERSION 3.22)

project(hynode LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTORCC_OPTIONS "--no-zstd")
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
find_package(Qt6 COMPONENTS QuickWidgets)
find_package(Qt6 COMPONENTS Sql)

qt_add_executable(hynode WIN32 MACOSX_BUNDLE
    ../common/buffer.cpp ../common/buffer.h
    ../common/common.h    ../common/guicommon.h
    ../common/hyplugin_interface.cpp ../common/hyplugin_interface.h
    ../common/hfs_interface.h ../common/hfs_interface.cpp
    ../common/hfs.h ../common/hfs.cpp
    ../common/hfsitem.h ../common/hfsitem.cpp
    ../common/colorrange.h
    ../common/
    ../common/datapack.h
    ../common/hyvalue.h
    ../common/sequencer.h
    ../common/flow.h
    ../common/task.h
    ../common/hdevice.h ../common/hdevice.cpp
    ../common/hactor.h ../common/hactor.cpp
    coreserver.cpp coreserver.h
    flower.h flower.cpp
    job.h job.cpp
    main.cpp
    nodecore.cpp nodecore.h
    pluginslot.cpp pluginslot.h
    slotter.cpp slotter.h
    unicore.cpp unicore.h
    hyperborg.qrc
    executor.h executor.cpp

    hud_qml/hudbutton.h hud_qml/hudbutton.cpp
    hud_qml/hudcalendar.h hud_qml/hudcalendar.cpp
    hud_qml/hudclock.h hud_qml/hudclock.cpp
    hud_qml/hudelement.h hud_qml/hudelement.cpp
    hud_qml/hudeventlist.h hud_qml/hudeventlist.cpp
    hud_qml/hudgarbage.h hud_qml/hudgarbage.cpp
    hud_qml/hudgauge.h hud_qml/hudgauge.cpp
    hud_qml/hudhfstree.h hud_qml/hudhfstree.cpp
    hud_qml/hudlibrary.h hud_qml/hudlibrary.cpp
    hud_qml/hudnavigator.h hud_qml/hudnavigator.cpp
    hud_qml/hudpowergrid.h hud_qml/hudpowergrid.cpp
    hud_qml/hudscreen.h hud_qml/hudscreen.cpp
    hud_qml/hudscreensaver.h hud_qml/hudscreensaver.cpp
    hud_qml/hudshoppinglist.h hud_qml/hudshoppinglist.cpp
    hud_qml/hudtimetable.h hud_qml/hudtimetable.cpp
    hud_qml/hudtodolist.h hud_qml/hudtodolist.cpp
    hud_qml/hudweather.h hud_qml/hudweather.cpp
)

target_include_directories(hynode PUBLIC
    .
    ../common
    ../common/entity
    hud
    hud_qml
    hsm
    hsm/tasks
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
    Qt::QuickWidgets
    Qt::Sql
)

if(LINUX)
    add_compile_definitions(PF_LINUX)
    add_compile_definitions(Q_COMPILER_INITIALIZER_LISTS)

    target_include_directories(hynode PUBLIC
        ../plugins/paradox
    )

    target_link_libraries(hynode PUBLIC
        Qt::Sql
    )
endif()

if(EMSCRIPTEN)
    add_compile_definitions(PF_EMSCRIPTEN)
    add_compile_definitions(WASM)
    add_compile_definitions(Q_COMPILER_INITIALIZER_LISTS)

    SET(GCC_HYPERBORG_COMPILE_FLAGS "")
#    SET(GCC_HYPERBORG_LINK_FLAGS    "-sGL_ENABLE_GET_PROC_ADDRESS")
    SET(GCC_HYPERBORG_LINK_FLAGS    "-lidbfs.js")
    SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_HYPERBORG_COMPILE_FLAGS}")
    SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_HYPERBORG_LINK_FLAGS}")

    target_compile_definitions(hynode PUBLIC
        WASM
    )

endif()

install(TARGETS hynode
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)
