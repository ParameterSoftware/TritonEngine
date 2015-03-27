#CMake will be used when actual releases start to get out but for now, manual configuiration shall be required
#TL;DR: CMake is not yet implemented

# cmake_minimum_required (VERSION 2.6)
# project (SGE)
# The version number.
# set (SGE_VERSION_MAJOR 0)
# set (SGE_VERSION_MINOR 0)
# set (SGE_VERSION_MICRO 1)
#
# configure a header file to pass some of the CMake settings
# to the source code
# configure_file (
#  "${PROJECT_SOURCE_DIR}/Config.h.in"
#  "${PROJECT_BINARY_DIR}SpartanEngine/includes/Config.h"
#  )
#
# include_directories("${PROJECT_BINARY_DIR}")
#
# include_directories ("${PROJECT_SOURCE_DIR}/SpartanEngine/includes")
# add_subdirectory (includes)
# set (EXTRA_LIBS ${EXTRA_LIBS} includes)
#
# target_link_libraries (SGE  ${EXTRA_LIBS})