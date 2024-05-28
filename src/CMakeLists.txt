cmake_minimum_required(VERSION 3.10)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
#find_package(Qt4 4.8.6 REQUIRED QtCore QtScript)
#find_package(Qt4 4.8.7 REQUIRED QtCore QtScript)
find_package(Qt5 REQUIRED COMPONENTS Core)

include(../dep/build_tools/cmake/deploy.cmake)
file (STRINGS ${PROJECT_SOURCE_DIR}/release_version.txt X_PROJECT_VERSION)

project(nfd_lib VERSION ${X_PROJECT_VERSION} LANGUAGES CXX)

set(X_COMPANYNAME "ntinfo")
set(X_PROJECTNAME "nfdlib")
set(X_MAINTAINER "horsicq@gmail.com")
set(X_DESCRIPTION "Nauz File Detector library")
set(X_HOMEPAGE "https://github.com/horsicq/nfd_library")
set(X_ORIGINAL_FILENAME "nfdlib")

deploy_init()

add_subdirectory(../dep/XCapstone/x86 XCapstone)
add_subdirectory(../dep/XArchive XArchive)
add_subdirectory(lib nfdlib)
