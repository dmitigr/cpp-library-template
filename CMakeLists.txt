# -*- cmake -*-
# Copyright (C) Dmitry Igrishin
# For conditions of distribution and use, see files LICENSE.txt or the_cpp_library.hpp

project(dmitigr_the_cpp_library)

cmake_minimum_required(VERSION 3.13)
cmake_policy(VERSION 3.13)

if (NOT (UNIX OR WIN32))
  message(FATAL_ERROR "unsupported target platform")
endif()

list(APPEND CMAKE_MODULE_PATH ${dmitigr_the_cpp_library_SOURCE_DIR}/cmake)
include(dmitigr)

set(dmitigr_the_cpp_library_version_part1 0)
set(dmitigr_the_cpp_library_version_part2 1)
add_definitions(-DDMITIGR_THE_CPP_LIBRARY_VERSION_PART1=${dmitigr_the_cpp_library_version_part1})
add_definitions(-DDMITIGR_THE_CPP_LIBRARY_VERSION_PART2=${dmitigr_the_cpp_library_version_part2})

# ------------------------------------------------------------------------------
# Build options
# ------------------------------------------------------------------------------

option(BUILD_SHARED_LIBS "Build shared library?" ON)
option(DMITIGR_THE_CPP_LIBRARY_HEADER_ONLY "Header-only library?" OFF)
option(DMITIGR_THE_CPP_LIBRARY_BUILD_TESTS "Build tests?" ON)

if(NOT DMITIGR_THE_CPP_LIBRARY_HEADER_ONLY)
  if(BUILD_SHARED_LIBS)
    message("Building of shared library is enabled.")
    add_definitions(-DDMITIGR_THE_CPP_LIBRARY_DLL_BUILDING)
  else()
    message("Building of static library is enabled.")
  endif()

  if(NOT DEFINED CMAKE_BUILD_TYPE OR NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING
      "Build type: Debug Release RelWithDebInfo MinSizeRel." FORCE)
  endif()
  message("Build type is ${CMAKE_BUILD_TYPE}")
else()
  message("Header-only mode is enabled")
endif()

if(DMITIGR_THE_CPP_LIBRARY_BUILD_TESTS)
  enable_testing()
  message("Building of tests is enabled")
endif()

# ------------------------------------------------------------------------------
# Installation options
# ------------------------------------------------------------------------------

if(UNIX)
  set(DMITIGR_THE_CPP_LIBRARY_CMAKE_INSTALL_DIR "share/dmitigr_the_cpp_library/cmake" CACHE
    STRING "Name of the installation directory for the CMake stuff relative to ${CMAKE_INSTALL_PREFIX}")
  set(DMITIGR_THE_CPP_LIBRARY_DOC_INSTALL_DIR "share/dmitigr_the_cpp_library/doc" CACHE
    STRING "Name of the installation directory for the documentation relative to ${CMAKE_INSTALL_PREFIX}")
  set(DMITIGR_THE_CPP_LIBRARY_LIB_INSTALL_DIR "lib" CACHE
    STRING "Name of the installation directory for the libraries relative to ${CMAKE_INSTALL_PREFIX}")
  set(DMITIGR_THE_CPP_LIBRARY_INCLUDE_INSTALL_DIR "include" CACHE
    STRING "Name of the installation directory for the includes relative to ${CMAKE_INSTALL_PREFIX}")
elseif(WIN32)
  # On Windows, CMAKE_INSTALL_PREFIX is $ENV{ProgramFiles}\\${CMAKE_PROJECT_NAME} by default. In turn:
  #   - on AMD64: ProgramFiles=%ProgramFiles%
  #   - on   x86: ProgramFiles=%ProgramFiles(x86)%
  # See: https://msdn.microsoft.com/en-us/library/aa384274.aspx
  set(DMITIGR_THE_CPP_LIBRARY_CMAKE_INSTALL_DIR "cmake" CACHE
    STRING "Name of share directory relative to ${CMAKE_INSTALL_PREFIX}")
  set(DMITIGR_THE_CPP_LIBRARY_DOC_INSTALL_DIR "doc" CACHE
    STRING "Name of the documentation directory relative to ${CMAKE_INSTALL_PREFIX}")
  set(DMITIGR_THE_CPP_LIBRARY_LIB_INSTALL_DIR "lib" CACHE
    STRING "Name of the library directory relative to ${CMAKE_INSTALL_PREFIX}")
  set(DMITIGR_THE_CPP_LIBRARY_INCLUDE_INSTALL_DIR "include" CACHE
    STRING "Name of includes directory relative to ${CMAKE_INSTALL_PREFIX}")
endif()

# ------------------------------------------------------------------------------
# Languages
# ------------------------------------------------------------------------------

enable_language(CXX)
set(CMAKE_CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)

include_directories(BEFORE ${CMAKE_CURRENT_SOURCE_DIR}/lib)
include_directories(BEFORE ${CMAKE_CURRENT_BINARY_DIR}/lib)

# ------------------------------------------------------------------------------
# Sources
# ------------------------------------------------------------------------------

set(dmitigr_the_cpp_library_root_headers
  lib/dmitigr/the_cpp_library.hpp
  )

set(dmitigr_the_cpp_library_header_only_headers
  lib/dmitigr/the_cpp_library/implementation_footer.hpp
  lib/dmitigr/the_cpp_library/implementation_header.hpp
  )

set(dmitigr_the_cpp_library_headers
  lib/dmitigr/the_cpp_library/dll.hpp
  lib/dmitigr/the_cpp_library/the_class.hpp
  lib/dmitigr/the_cpp_library/types_fwd.hpp
  )

set(dmitigr_the_cpp_library_implementations
  lib/dmitigr/the_cpp_library/the_class.cpp
  )

set(dmitigr_the_cpp_library_transunits
  lib/dmitigr/the_cpp_library.cpp
  )

set(dmitigr_the_cpp_library_sources
  ${dmitigr_the_cpp_library_root_headers}
  ${dmitigr_the_cpp_library_header_only_headers}
  ${dmitigr_the_cpp_library_headers}
  ${dmitigr_the_cpp_library_implementations}
  ${dmitigr_the_cpp_library_transunits}
  )

set_source_files_properties(
  ${dmitigr_the_cpp_library_implementations}

  PROPERTIES
  HEADER_FILE_ONLY ON)

# ------------------------------------------------------------------------------
# Targets
# ------------------------------------------------------------------------------

# Note: Multi-configuration generators (VS, Xcode) appends a per-configuration
# subdirectory to CMAKE_RUNTIME_OUTPUT_DIRECTORY unless a generator expression
# is used.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}")

if(NOT DMITIGR_THE_CPP_LIBRARY_HEADER_ONLY)
  if(BUILD_SHARED_LIBS)
    set(dmitigr_the_cpp_library_target "dmitigr_the_cpp_library")
  else()
    set(dmitigr_the_cpp_library_target "dmitigr_the_cpp_library_static")
  endif()

  add_library(${dmitigr_the_cpp_library_target} ${dmitigr_the_cpp_library_sources})

  if(BUILD_SHARED_LIBS)
    target_compile_definitions(dmitigr_the_cpp_library PUBLIC -DDMITIGR_THE_CPP_LIBRARY_DLL)
  endif()

  set_target_properties(${dmitigr_the_cpp_library_target}
    PROPERTIES
    LINKER_LANGUAGE "CXX"
    POSITION_INDEPENDENT_CODE True
    VERSION ${dmitigr_the_cpp_library_version_part1}.${dmitigr_the_cpp_library_version_part2}
    DEBUG_POSTFIX "d")

  dmitigr_target_compile_options(${dmitigr_the_cpp_library_target})
else() # for header-only
  set(dmitigr_the_cpp_library_target "dmitigr_the_cpp_library_interface")

  add_library(dmitigr_the_cpp_library_interface INTERFACE)

  target_compile_definitions(dmitigr_the_cpp_library_interface INTERFACE -DDMITIGR_THE_CPP_LIBRARY_HEADER_ONLY)
endif()

# ------------------------------------------------------------------------------
# Dependencies
# ------------------------------------------------------------------------------

#
# dmitigr_common
#

find_package(dmitigr_common REQUIRED)
message("Using ${dmitigr_common_library} library")

# --------------------------------------

if(NOT DMITIGR_THE_CPP_LIBRARY_HEADER_ONLY)
  target_link_libraries(${dmitigr_the_cpp_library_target} PRIVATE ${dmitigr_common_library})
else()
  target_link_libraries(dmitigr_the_cpp_library_interface INTERFACE ${dmitigr_common_library})
endif()

# ------------------------------------------------------------------------------
# Installing
# ------------------------------------------------------------------------------

install(FILES ${dmitigr_the_cpp_library_root_headers}
  DESTINATION ${DMITIGR_THE_CPP_LIBRARY_INCLUDE_INSTALL_DIR}/dmitigr)

if(DMITIGR_THE_CPP_LIBRARY_HEADER_ONLY)
  install(FILES ${dmitigr_the_cpp_library_header_only_headers}
    DESTINATION ${DMITIGR_THE_CPP_LIBRARY_INCLUDE_INSTALL_DIR}/dmitigr/the_cpp_library)
endif()

install(FILES ${dmitigr_the_cpp_library_headers}
  DESTINATION ${DMITIGR_THE_CPP_LIBRARY_INCLUDE_INSTALL_DIR}/dmitigr/the_cpp_library)

if(NOT DMITIGR_THE_CPP_LIBRARY_HEADER_ONLY)
  install(TARGETS ${dmitigr_the_cpp_library_target}
    EXPORT ${dmitigr_the_cpp_library_target}_export
    ARCHIVE  DESTINATION ${DMITIGR_THE_CPP_LIBRARY_LIB_INSTALL_DIR}
    LIBRARY  DESTINATION ${DMITIGR_THE_CPP_LIBRARY_LIB_INSTALL_DIR}
    RUNTIME  DESTINATION ${DMITIGR_THE_CPP_LIBRARY_LIB_INSTALL_DIR}
    INCLUDES DESTINATION ${DMITIGR_THE_CPP_LIBRARY_INCLUDE_INSTALL_DIR})
else()
  install(TARGETS dmitigr_the_cpp_library_interface
    EXPORT dmitigr_the_cpp_library_interface_export
    INCLUDES DESTINATION ${DMITIGR_THE_CPP_LIBRARY_INCLUDE_INSTALL_DIR})

  install(FILES ${dmitigr_the_cpp_library_implementations}
    DESTINATION ${DMITIGR_THE_CPP_LIBRARY_INCLUDE_INSTALL_DIR}/dmitigr/the_cpp_library)
endif()

install(EXPORT ${dmitigr_the_cpp_library_target}_export
  DESTINATION ${DMITIGR_THE_CPP_LIBRARY_CMAKE_INSTALL_DIR}
  FILE ${dmitigr_the_cpp_library_target}-config.cmake)

# ------------------------------------------------------------------------------
# Uninstalling
# ------------------------------------------------------------------------------

add_custom_target(uninstall)

add_custom_command(TARGET uninstall PRE_BUILD
  COMMAND cmake -E remove -f ${CMAKE_INSTALL_PREFIX}/${DMITIGR_THE_CPP_LIBRARY_CMAKE_INSTALL_DIR}/dmitigr_the_cpp_library*
  COMMAND cmake -E remove -f ${CMAKE_INSTALL_PREFIX}/${DMITIGR_THE_CPP_LIBRARY_DOC_INSTALL_DIR}/dmitigr_the_cpp_library*
  COMMAND cmake -E remove -f ${CMAKE_INSTALL_PREFIX}/${DMITIGR_THE_CPP_LIBRARY_LIB_INSTALL_DIR}/dmitigr_the_cpp_library*
  COMMAND cmake -E remove -f ${CMAKE_INSTALL_PREFIX}/${DMITIGR_THE_CPP_LIBRARY_LIB_INSTALL_DIR}/libdmitigr_the_cpp_library*
  COMMAND cmake -E remove -f ${CMAKE_INSTALL_PREFIX}/${DMITIGR_THE_CPP_LIBRARY_INCLUDE_INSTALL_DIR}/dmitigr/the_cpp_library*
  COMMAND cmake -E remove_directory ${CMAKE_INSTALL_PREFIX}/${DMITIGR_THE_CPP_LIBRARY_INCLUDE_INSTALL_DIR}/dmitigr/the_cpp_library
  )

# ------------------------------------------------------------------------------

if(DMITIGR_THE_CPP_LIBRARY_BUILD_TESTS)
  add_subdirectory(tests)
endif()
