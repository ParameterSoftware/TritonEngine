# -----------------------------------------------------------------------------
# Copyright (c) 2014 GarageGames, LLC
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to
# deal in the Software without restriction, including without limitation the
# rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
# sell copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
# IN THE SOFTWARE.
# -----------------------------------------------------------------------------
project("SpartanEngine")
set(SPARTAN_TEMPLATE "Full" CACHE STRING "the template to use")
if(NOT projectDir)
set(projectDir "${CMAKE_SOURCE_DIR}/My Projects/${GAME_NAME}")
endif()
if(NOT projectOutDir)
set(projectOutDir "${projectDir}/game")
endif()
if(NOT projectSrcDir)
set(projectSrcDir "${projectDir}/source")
endif()
set(libDir "${CMAKE_SOURCE_DIR}/Engine/lib")
set(srcDir "${CMAKE_SOURCE_DIR}/Engine/source")
set(cmakeDir "${CMAKE_SOURCE_DIR}/Tools/CMake")
# hide some things
mark_as_advanced(CMAKE_INSTALL_PREFIX)
mark_as_advanced(CMAKE_CONFIGURATION_TYPES)
# output folders
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${projectOutDir}/game)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${projectOutDir}/game)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${projectOutDir}/game)
###############################################################################
### Source File Handling
###############################################################################
# finds and adds sources files in a folder
macro(addPath dir)
set(tmp_files "")
set(glob_config GLOB)
if(${ARGC} GREATER 1 AND "${ARGV1}" STREQUAL "REC")
set(glob_config GLOB_RECURSE)
endif()
file(${glob_config} tmp_files
${dir}/*.cpp
${dir}/*.c
${dir}/*.cc
${dir}/*.h
${dir}/*.asm)
LIST(APPEND ${PROJECT_NAME}_files "${tmp_files}")
LIST(APPEND ${PROJECT_NAME}_paths "${dir}")
#message(STATUS "addPath ${PROJECT_NAME} : ${tmp_files}")
endmacro()
# adds a file to the sources
macro(addFile filename)
LIST(APPEND ${PROJECT_NAME}_files "${filename}")
#message(STATUS "addFile ${PROJECT_NAME} : ${filename}")
endmacro()
# finds and adds sources files in a folder recursively
macro(addPathRec dir)
addPath("${dir}" "REC")
endmacro()
###############################################################################
### Definition Handling
###############################################################################
macro(__addDef def config)
# two possibilities: a) target already known, so add it directly, or b) target not yet known, so add it to its cache
if(TARGET ${PROJECT_NAME})
#message(STATUS "directly applying defs: ${PROJECT_NAME} with config ${config}: ${def}")
if("${config}" STREQUAL "")
set_property(TARGET ${PROJECT_NAME} APPEND PROPERTY COMPILE_DEFINITIONS "${def}")
else()
set_property(TARGET ${PROJECT_NAME} APPEND PROPERTY COMPILE_DEFINITIONS_${config} "${def}")
endif()
else()
list(APPEND ${PROJECT_NAME}_defs_${config} ${def})
#message(STATUS "added definition to cache: ${PROJECT_NAME}_defs_${config}: ${${PROJECT_NAME}_defs_${config}}")
endif()
endmacro()
# adds a definition: argument 1: Nothing(for all), _DEBUG, _RELEASE, <more build configurations>
macro(addDef def)
set(def_configs "")
if(${ARGC} GREATER 1)
foreach(config "${ARGV1}")
__addDef(${def} ${config})
endforeach()
else()
__addDef(${def} "")
endif()
endmacro()
# this applies cached definitions onto the target
macro(_process_defs)
if(DEFINED ${PROJECT_NAME}_defs_)
set_property(TARGET ${PROJECT_NAME} APPEND PROPERTY COMPILE_DEFINITIONS "${${PROJECT_NAME}_defs_}")
#message(STATUS "applying defs to project ${PROJECT_NAME} on all configs: ${${PROJECT_NAME}_defs_}")
endif()
foreach(def_config ${CMAKE_CONFIGURATION_TYPES})
string(TOUPPER "${def_config}" def_config)
if(DEFINED ${PROJECT_NAME}_defs_${def_config})
set_property(TARGET ${PROJECT_NAME} APPEND PROPERTY COMPILE_DEFINITIONS_${def_config} "${${PROJECT_NAME}_defs_${def_config}}")
#message(STATUS "applying defs to project ${PROJECT_NAME} on config ${def_config}: ${${PROJECT_NAME}_defs_${def_config}}")
endif()
endforeach()
endmacro()
###############################################################################
### Source Library Handling
###############################################################################
macro(addLibSrc libPath)
set(cached_project_name ${PROJECT_NAME})
include(${libPath})
project(${cached_project_name})
endmacro()
###############################################################################
### Linked Library Handling
###############################################################################
macro(addLib libs)
foreach(lib ${libs})
# check if we can build it ourselfs
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/libraries/${lib}.cmake")
addLibSrc("${CMAKE_CURRENT_SOURCE_DIR}/libraries/${lib}.cmake")
endif()
# then link against it
# two possibilities: a) target already known, so add it directly, or b) target not yet known, so add it to its cache
if(TARGET ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} "${lib}")
else()
list(APPEND ${PROJECT_NAME}_libs ${lib})
endif()
endforeach()
endmacro()
# this applies cached definitions onto the target
macro(_process_libs)
if(DEFINED ${PROJECT_NAME}_libs)
target_link_libraries(${PROJECT_NAME} "${${PROJECT_NAME}_libs}")
endif()
endmacro()
###############################################################################
### Include Handling
###############################################################################
#macro(addInclude incPath)
#if(TARGET ${PROJECT_NAME})
#set_property(TARGET ${PROJECT_NAME} APPEND PROPERTY INCLUDE_DIRECTORIES "${incPath}")
#else()
#list(APPEND ${PROJECT_NAME}_includes ${incPath})
#endif()
#endmacro()
# this applies cached definitions onto the target
#macro(_process_includes)
#if(DEFINED ${PROJECT_NAME}_includes)
#set_property(TARGET ${PROJECT_NAME} APPEND PROPERTY INCLUDE_DIRECTORIES "${${PROJECT_NAME}_includes}")
#endif()
#endmacro()
###############################################################################
macro(_postTargetProcess)
_process_includes()
_process_defs()
_process_libs()
endmacro()
# adds a path to search for libs
macro(addLibPath dir)
link_directories(${dir})
endmacro()
# creates a proper filter for VS
macro(generateFilters relDir)
foreach(f ${${PROJECT_NAME}_files})
# Get the path of the file relative to ${DIRECTORY},
# then alter it (not compulsory)
file(RELATIVE_PATH SRCGR ${relDir} ${f})
set(SRCGR "${PROJECT_NAME}/${SRCGR}")
# Extract the folder, ie remove the filename part
string(REGEX REPLACE "(.*)(/[^/]*)$" "\\1" SRCGR ${SRCGR})
# do not have any ../ dirs
string(REPLACE "../" "" SRCGR ${SRCGR})
# Source_group expects \\ (double antislash), not / (slash)
string(REPLACE / \\ SRCGR ${SRCGR})
#STRING(REPLACE "//" "/" SRCGR ${SRCGR})
#message(STATUS "FILE: ${f} -> ${SRCGR}")
source_group("${SRCGR}" FILES ${f})
endforeach()
endmacro()
# creates a proper filter for VS
macro(generateFiltersSpecial relDir)
foreach(f ${${PROJECT_NAME}_files})
# Get the path of the file relative to ${DIRECTORY},
# then alter it (not compulsory)
file(RELATIVE_PATH SRCGR ${relDir} ${f})
set(SRCGR "SPARTAN3d/${SRCGR}")
# Extract the folder, ie remove the filename part
string(REGEX REPLACE "(.*)(/[^/]*)$" "\\1" SRCGR ${SRCGR})
# do not have any ../ dirs
string(REPLACE "../" "" SRCGR ${SRCGR})
IF("${SRCGR}" MATCHES "^SPARTAN3d/My Projects/.*$")
string(REPLACE "SPARTAN3d/My Projects/${PROJECT_NAME}/" "" SRCGR ${SRCGR})
string(REPLACE "/source" "" SRCGR ${SRCGR})
endif()
# Source_group expects \\ (double antislash), not / (slash)
string(REPLACE / \\ SRCGR ${SRCGR})
#STRING(REPLACE "//" "/" SRCGR ${SRCGR})
IF(EXISTS "${f}" AND NOT IS_DIRECTORY "${f}")
#message(STATUS "FILE: ${f} -> ${SRCGR}")
source_group("${SRCGR}" FILES ${f})
endif()
endforeach()
endmacro()
# macro to add a static library
macro(finishLibrary)
# more paths?
if(${ARGC} GREATER 0)
foreach(dir ${ARGV0})
addPath("${dir}")
endforeach()
endif()
# now inspect the paths we got
set(firstDir "")
foreach(dir ${${PROJECT_NAME}_paths})
if("${firstDir}" STREQUAL "")
set(firstDir "${dir}")
endif()
endforeach()
generateFilters("${firstDir}")
# set per target compile flags
if(SPARTAN_CXX_FLAGS_${PROJECT_NAME})
set_source_files_properties(${${PROJECT_NAME}_files} PROPERTIES COMPILE_FLAGS "${SPARTAN_CXX_FLAGS_${PROJECT_NAME}}")
else()
set_source_files_properties(${${PROJECT_NAME}_files} PROPERTIES COMPILE_FLAGS "${SPARTAN_CXX_FLAGS_LIBS}")
endif()
if(SPARTAN_STATIC)
add_library("${PROJECT_NAME}" STATIC ${${PROJECT_NAME}_files})
else()
add_library("${PROJECT_NAME}" SHARED ${${PROJECT_NAME}_files})
endif()
# omg - only use the first folder ... otherwise we get lots of header name collisions
#foreach(dir ${${PROJECT_NAME}_paths})
addInclude("${firstDir}")
#endforeach()
_postTargetProcess()
endmacro()
# macro to add an executable
macro(finishExecutable)
# now inspect the paths we got
set(firstDir "")
foreach(dir ${${PROJECT_NAME}_paths})
if("${firstDir}" STREQUAL "")
set(firstDir "${dir}")
endif()
endforeach()
generateFiltersSpecial("${firstDir}")
# set per target compile flags
if(SPARTAN_CXX_FLAGS_${PROJECT_NAME})
set_source_files_properties(${${PROJECT_NAME}_files} PROPERTIES COMPILE_FLAGS "${SPARTAN_CXX_FLAGS_${PROJECT_NAME}}")
else()
set_source_files_properties(${${PROJECT_NAME}_files} PROPERTIES COMPILE_FLAGS "${SPARTAN_CXX_FLAGS_EXECUTABLES}")
endif()
add_executable("${PROJECT_NAME}" WIN32 ${${PROJECT_NAME}_files})
addInclude("${firstDir}")
_postTargetProcess()
endmacro()
macro(setupVersionNumbers)
set(GAME_VERSION_MAJOR 1 CACHE INTEGER "")
set(GAME_VERSION_MINOR 0 CACHE INTEGER "")
set(GAME_VERSION_PATCH 0 CACHE INTEGER "")
set(GAME_VERSION_TWEAK 0 CACHE INTEGER "")
mark_as_advanced(GAME_VERSION_TWEAK)
MATH(EXPR GAME_VERSION "${GAME_VERSION_MAJOR} * 1000 + ${GAME_VERSION_MINOR} * 100 + ${GAME_VERSION_PATCH} * 10 + ${GAME_VERSION_TWEAK}")
set(GAME_VERSION_STRING "${GAME_VERSION_MAJOR}.${GAME_VERSION_MINOR}.${GAME_VERSION_PATCH}.${GAME_VERSION_TWEAK}")
#message(STATUS "version numbers: ${GAME_VERSION} / ${GAME_VERSION_STRING}")
endmacro()
macro(setupPackaging)
INCLUDE(CPack)
# only enable zips for now
set(CPACK_BINARY_NSIS OFF CACHE INTERNAL "" FORCE)
set(CPACK_BINARY_ZIP ON CACHE INTERNAL "" FORCE)
set(CPACK_SOURCE_ZIP OFF CACHE INTERNAL "" FORCE)
SET(CPACK_GENERATOR "ZIP")
SET(CPACK_PACKAGE_VENDOR "${PROJECT_NAME}")
SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "${PROJECT_NAME}")
SET(CPACK_INCLUDE_TOPLEVEL_DIRECTORY 1)
SET(CPACK_OUTPUT_FILE_PREFIX "${projectDir}/packages/${PROJECT_NAME}")
SET(CPACK_PACKAGE_INSTALL_DIRECTORY "")
#SET(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/ReadMe.txt")
#SET(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/Copyright.txt")
SET(CPACK_PACKAGE_VERSION_MAJOR "${GAME_VERSION_MAJOR}")
SET(CPACK_PACKAGE_VERSION_MINOR "${GAME_VERSION_MINOR}")
SET(CPACK_PACKAGE_VERSION_PATCH "${GAME_VERSION_PATCH}")
#SET(CPACK_PACKAGE_EXECUTABLES "${PROJECT_NAME}" "${PROJECT_NAME}")
SET(CPACK_SOURCE_PACKAGE_FILE_NAME "${PROJECT_NAME}-${GAME_VERSION_STRING}")
#SET(CPACK_SOURCE_STRIP_FILES "")
endmacro()
# always static for now
set(SPARTAN_STATIC ON)
#option(SPARTAN_STATIC "enables or disable static" OFF)
if(WIN32)
set(SPARTAN_CXX_FLAGS_EXECUTABLES "/wd4018 /wd4100 /wd4121 /wd4127 /wd4130 /wd4244 /wd4245 /wd4389 /wd4511 /wd4512 /wd4800 /wd4995 " CACHE TYPE STRING)
mark_as_advanced(SPARTAN_CXX_FLAGS_EXECUTABLES)
set(SPARTAN_CXX_FLAGS_LIBS "/W0" CACHE TYPE STRING)
mark_as_advanced(SPARTAN_CXX_FLAGS_LIBS)
set(SPARTAN_CXX_FLAGS_COMMON "-DUNICODE -D_UNICODE /MP /O2 /Ob2 /Oi /Ot /Oy /GT /Zi /W4 /nologo /GF /EHsc /GS- /Gy- /Qpar- /arch:SSE2 /fp:fast /fp:except- /GR /Zc:wchar_t- /D_CRT_SECURE_NO_WARNINGS" CACHE TYPE STRING)
mark_as_advanced(SPARTAN_CXX_FLAGS_COMMON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${SPARTAN_CXX_FLAGS_COMMON}")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${CMAKE_CXX_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "/LARGEADDRESSAWARE")
#set(STATIC_LIBRARY_FLAGS "/OPT:NOREF")
# Force static runtime libraries
if(SPARTAN_STATIC)
FOREACH(flag
CMAKE_C_FLAGS_RELEASE
CMAKE_C_FLAGS_RELWITHDEBINFO
CMAKE_C_FLAGS_DEBUG
CMAKE_C_FLAGS_DEBUG_INIT
CMAKE_CXX_FLAGS_RELEASE
CMAKE_CXX_FLAGS_RELWITHDEBINFO
CMAKE_CXX_FLAGS_DEBUG
CMAKE_CXX_FLAGS_DEBUG_INIT)
STRING(REPLACE "/MD" "/MT" "${flag}" "${${flag}}")
SET("${flag}" "${${flag}} /EHsc")
ENDFOREACH()
endif()
else()
# TODO: improve default settings on other platforms
set(SPARTAN_CXX_FLAGS_EXECUTABLES "" CACHE TYPE STRING)
mark_as_advanced(SPARTAN_CXX_FLAGS_EXECUTABLES)
set(SPARTAN_CXX_FLAGS_LIBS "" CACHE TYPE STRING)
mark_as_advanced(SPARTAN_CXX_FLAGS_LIBS)
set(SPARTAN_CXX_FLAGS_COMMON "" CACHE TYPE STRING)
mark_as_advanced(SPARTAN_CXX_FLAGS)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${SPARTAN_CXX_FLAGS}")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${CMAKE_CXX_FLAGS}")
endif()
if(UNIX)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${projectOutDir}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${projectOutDir}")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${projectOutDir}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${projectOutDir}")
endif()
# fix the debug/release subfolders on windows
if(MSVC)
FOREACH(CONF ${CMAKE_CONFIGURATION_TYPES})
# Go uppercase (DEBUG, RELEASE...)
STRING(TOUPPER "${CONF}" CONF)
#SET("CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${CONF}" "${projectOutDir}")
SET("CMAKE_RUNTIME_OUTPUT_DIRECTORY_${CONF}" "${projectOutDir}")
ENDFOREACH()