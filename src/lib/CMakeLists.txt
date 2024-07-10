cmake_minimum_required(VERSION 3.10)

project(nfd LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message(${PROJECT_SOURCE_DIR})

if(WIN32)
    add_definitions(-DWIN32)
    if(${QT_VERSION_MAJOR} LESS 5)
        set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zc:wchar_t-")
        set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /Zc:wchar_t-")
        set (CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Zc:wchar_t-")
        set (CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL} /Zc:wchar_t-")
    endif()
endif()

add_definitions(
    -DQT_DEPRECATED_WARNINGS
    -DLIB_SOURCE_LIBRARY
    -DUSE_DEX
    -DUSE_PDF
    -DUSE_ARCHIVE
    -DUSE_YARA
    )

include(${CMAKE_CURRENT_LIST_DIR}/../../dep/SpecAbstract/specabstract.cmake)
include(GNUInstallDirs)

set(PROJECT_SOURCES
        ${SPECABSTRACT_SOURCES}
        nfd_lib.cpp
        nfd_lib.h
)
    
if(DIE_BUILD_AS_STATIC)
    message(STATUS "Building NfdLib as static")
    add_library(nfd STATIC
        ${PROJECT_SOURCES}
    )
else()
    message(STATUS "Building NfdLib as shared")
    add_library(nfd SHARED
        ${PROJECT_SOURCES}
    )
endif()

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

target_link_libraries(nfd PRIVATE bzip2)
target_link_libraries(nfd PRIVATE lzma)
target_link_libraries(nfd PRIVATE zlib)
target_link_libraries(nfd PRIVATE capstone_x86)

if(${QT_VERSION_MAJOR} EQUAL 4)
    target_link_libraries(nfd PRIVATE Qt4::QtCore)
endif()

if(${QT_VERSION_MAJOR} EQUAL 5)
    target_link_libraries(nfd PRIVATE Qt${QT_VERSION_MAJOR}::Core)
endif()

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    target_link_libraries(nfd PRIVATE Qt${QT_VERSION_MAJOR}::Core)
endif()

if(WIN32)
    target_link_libraries(nfd PRIVATE Wintrust)
    target_link_libraries(nfd PRIVATE Crypt32)
    target_link_libraries(nfd PRIVATE comsuppwd)
endif()

if(WIN32)
    install (TARGETS nfd DESTINATION "./")
    install (FILES ../include/nfd.h DESTINATION "./include"  OPTIONAL)
    deploy_qt()
    deploy_msvc()
else()
    install (TARGETS nfd DESTINATION ${CMAKE_INSTALL_LIBDIR})
    install (FILES ../include/nfd.h DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/nfdlib"  OPTIONAL)
endif()
