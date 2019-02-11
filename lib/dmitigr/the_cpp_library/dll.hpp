// -*- C++ -*-
// Copyright (C) Dmitry Igrishin
// For conditions of distribution and use, see files LICENSE.txt or the_cpp_library.hpp

/*
 * This file must be adapted for every API individually!
 */

#ifndef DMITIGR_THE_CPP_LIBRARY_DLL_HPP
#define DMITIGR_THE_CPP_LIBRARY_DLL_HPP

#ifdef _WIN32
  #ifdef DMITIGR_THE_CPP_LIBRARY_DLL_BUILDING
    #define DMITIGR_THE_CPP_LIBRARY_API __declspec(dllexport)
  #else
    #if DMITIGR_THE_CPP_LIBRARY_DLL
      #define DMITIGR_THE_CPP_LIBRARY_API __declspec(dllimport)
    #else /* static or header-only library on Windows */
      #define DMITIGR_THE_CPP_LIBRARY_API
    #endif
  #endif
#else /* Unix */
  #define DMITIGR_THE_CPP_LIBRARY_API
#endif

#endif // DMITIGR_THE_CPP_LIBRARY_DLL_HPP
