cmake_minimum_required(VERSION 3.22)
project(Button)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC_MACRO_NAMES ON)
set(CMAKE_PREFIX_PATH "C:\\Qt\\Qt5.12.12\\5.12.12\\mingw73_64\\lib\\cmake")

find_package(Qt5Widgets REQUIRED)
add_executable(Button main.cpp)
target_link_libraries(Button Qt5::Widgets)
