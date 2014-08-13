cmake_minimum_required (VERSION 2.6)

set(GAME_NAME "" CACHE STRING "the game name")

if("${GAME_NAME}" STREQUAL "")
	message(FATAL_ERROR "Please set GAME_NAME first")
endif()

project(${GAME_NAME})

add_subdirectory(Tools/CMake)