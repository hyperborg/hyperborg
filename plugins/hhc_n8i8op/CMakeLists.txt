# Generated from hhc_n8i8op.pri.

cmake_minimum_required(VERSION 3.16)
project(hhc_n8i8op LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

INCLUDE_DIRECTORIES(../../common)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(NOT DEFINED INSTALL_EXAMPLESDIR)
  set(INSTALL_EXAMPLESDIR "examples")
endif()

set(INSTALL_EXAMPLEDIR "${INSTALL_EXAMPLESDIR}")

find_package(Qt6 COMPONENTS Core REQUIRED)
find_package(Qt6 COMPONENTS Network REQUIRED)

qt_add_library(hhc_n8i8op SHARED
    ../../common/common.h
    ../../common/hyplugin_interface.cpp ../../common/hyplugin_interface.h
    ../../common/hplugin.h  ../../common/hplugin.cpp
    ../../common/hfs_interface.h
    ../../common/hfsitem.cpp ../../common/hfsitem.h
    ../../common/tcpsocket.cpp ../../common/tcpsocket.h
    hhc_n8i8op.cpp hhc_n8i8op.h
    hhc_n8i8op_device.cpp hhc_n8i8op_device.h
)
target_link_libraries(hhc_n8i8op PUBLIC
    Qt::Core
    Qt::Network
)

install(TARGETS hhc_n8i8op
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)
