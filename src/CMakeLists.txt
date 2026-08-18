cmake_minimum_required(VERSION 3.10)

# project() MUST precede find_package(Qt...) -- before it no language is enabled,
# Qt5's imported targets are created STATIC, and CMake then links them through
# IMPORTED_LOCATION (bin\Qt5*.dll) instead of IMPORTED_IMPLIB (lib\Qt5*.lib),
# producing LNK1107 on the .dll. ${PROJECT_SOURCE_DIR} is unusable for the version
# file (empty pre-project(), src/ afterwards), so address it relative to this list
# file, which is the repo root standalone and from the root build alike.
file(STRINGS ${CMAKE_CURRENT_LIST_DIR}/../release_version.txt X_PROJECT_VERSION)

project(nfd_lib VERSION ${X_PROJECT_VERSION} LANGUAGES CXX)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
#find_package(Qt4 4.8.6 REQUIRED QtCore QtScript)
#find_package(Qt4 4.8.7 REQUIRED QtCore QtScript)
find_package(Qt5 REQUIRED COMPONENTS Core)

include(../dep/build_tools/cmake/deploy.cmake)

set(X_COMPANYNAME "ntinfo")
set(X_PROJECTNAME "nfdlib")
set(X_MAINTAINER "horsicq@gmail.com")
set(X_DESCRIPTION "Nauz File Detector library")
set(X_HOMEPAGE "https://github.com/horsicq/nfd_library")
set(X_ORIGINAL_FILENAME "nfdlib")

deploy_init()

add_subdirectory(../dep/XCapstone/x86 XCapstone)
add_subdirectory(../dep/XArchive XArchive)
add_subdirectory(../dep/Formats/xsimd XSIMD)
add_subdirectory(lib nfdlib)
