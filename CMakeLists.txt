cmake_minimum_required (VERSION 2.8)
project(hockey-manager)

set(ClanLib_MAJOR_VERSION 2)
set(ClanLib_MINOR_VERSION 3)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(src)
