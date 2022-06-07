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
    ../common/hsettings.cpp ../common/hsettings.h
    ../common/hyobject.cpp ../common/hyobject.h
    ../common/hyplugin.cpp ../common/hyplugin.h
    ../common/microcode.cpp ../common/microcode.h
    ../common/qgraphicsgloweffect.cpp ../common/qgraphicsgloweffect.h
    ../common/hfs.h ../common/hfs.cpp	
    beacon.cpp beacon.h
    coreserver.cpp coreserver.h
    hud.h hud.cpp
    hudfactory.h hudfactory.cpp
    main.cpp
    nodecore.cpp nodecore.h
    pluginslot.cpp pluginslot.h
    slotter.cpp slotter.h
    unicore.cpp unicore.h
    vcpu.cpp vcpu.h
)
target_include_directories(hynode PUBLIC
    .
    ../common
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
    target_include_directories(hynode PUBLIC
        ../plugins/adminpanel
    )

    target_compile_definitions(hynode PUBLIC
        WASM
    )

endif()


install(TARGETS hynode
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)
