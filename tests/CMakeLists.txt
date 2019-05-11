# -*- cmake -*-
# Copyright (C) Dmitry Igrishin
# For conditions of distribution and use, see files LICENSE.txt or the_cpp_library.hpp

if(NOT DMITIGR_THE_CPP_LIBRARY_BUILD_TESTS)
  return()
endif()

remove_definitions(-DDMITIGR_THE_CPP_LIBRARY_DLL_BUILDING)

foreach(t unit1)
  add_executable(${t} ${t}.cpp)
  target_link_libraries(${t} ${dmitigr_the_cpp_library_target} ${dmitigr_common_library})
  dmitigr_target_compile_options(${t})
  add_test(NAME ${t} COMMAND ${t})
endforeach()

if (WIN32)
  set(dmitigr_the_cpp_library_resource_destination_dir "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$<CONFIG>")
elseif (UNIX)
  set(dmitigr_the_cpp_library_resource_destination_dir "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
endif()
