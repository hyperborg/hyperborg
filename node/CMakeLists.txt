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
find_package(Qt6 COMPONENTS StateMachine)

qt_add_executable(hynode WIN32 MACOSX_BUNDLE
    ../common/buffer.cpp ../common/buffer.h
    ../common/common.h    ../common/guicommon.h
    ../common/hyplugin_interface.cpp ../common/hyplugin_interface.h
    ../common/hfs_interface.h ../common/hfs_interface.cpp
    ../common/hfs.h ../common/hfs.cpp
    ../common/hfsitem.h ../common/hfsitem.cpp
    ../common/
    ../common/datapack.h
    ../common/hyvalue.h
    ../common/sequencer.h
    ../common/flow.h
    ../common/task.h
    ../common/hplugin.h ../common/hplugin.cpp
    ../common/hdevice.h ../common/hdevice.cpp
    ../common/hactor.h ../common/hactor.cpp
    ../common/hb_lookandfeel.h ../common/hb_lookandfeel.cpp 
    coreserver.cpp coreserver.h
    flower.h flower.cpp
    job.h job.cpp
    main.cpp
    nodecore.cpp nodecore.h
    pluginslot.cpp pluginslot.h
    unicore.cpp unicore.h
    hyperborg.qrc
    executor.h executor.cpp
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
    Qt::StateMachine
)

if(PF_LINUX)
    message("--LINUX 2--")
    add_compile_definitions(PF_LINUX)
    add_compile_definitions(Q_COMPILER_INITIALIZER_LISTS)

    target_include_directories(hynode PUBLIC
        ../plugins/paradox
    )

    target_link_libraries(hynode PUBLIC
        Qt::Sql
    )
endif()

if(PF_WASM)
    message("--EMSCRIPTEN 2 --")
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

if(PF_ANDROID)
    message("--ANDROID 2 --")
endif()

install(TARGETS hynode
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)
