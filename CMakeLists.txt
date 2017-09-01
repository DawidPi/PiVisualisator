cmake_minimum_required(VERSION 3.7)
project(PiVisualisator)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ";" ${QT5_PACKAGE_DIR})

find_package(Qt5Widgets REQUIRED)

add_definitions(-DQT_NO_KEYWORDS)

set(SOURCES
        main.cpp
        MainWindow.cpp
        MainWindow.hpp Data2PixmapAdapter.cpp Data2PixmapAdapter.hpp ImageData.cpp ImageData.hpp ImageLabel.cpp ImageLabel.hpp QemuManager.cpp QemuManager.hpp Settings.cpp Settings.hpp)

add_executable(${PROJECT_NAME} ${SOURCES})
qt5_use_modules(${PROJECT_NAME} Widgets Core)