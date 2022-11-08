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
    ../../common/hyobject.cpp ../../common/hyobject.h
    ../../common/hyplugin.cpp ../../common/hyplugin.h
    ../../common/hdevice.cpp ../../common/hdevice.h
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
