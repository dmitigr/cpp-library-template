// -*- C++ -*-
// Copyright (C) Dmitry Igrishin
// For conditions of distribution and use, see files LICENSE.txt or the_cpp_library.hpp

#ifndef DMITIGR_THE_CPP_LIBRARY_INLINE
  #if defined(DMITIGR_THE_CPP_LIBRARY_HEADER_ONLY) && !defined(DMITIGR_THE_CPP_LIBRARY_HEADER_ONLY)
    #define DMITIGR_THE_CPP_LIBRARY_INLINE inline
  #else
    #define DMITIGR_THE_CPP_LIBRARY_INLINE
  #endif
#endif  // DMITIGR_THE_CPP_LIBRARY_INLINE

#ifndef DMITIGR_THE_CPP_LIBRARY_NOMINMAX
  #ifdef _WIN32
    #ifndef NOMINMAX
      #define NOMINMAX
      #define DMITIGR_THE_CPP_LIBRARY_NOMINMAX
    #endif
  #endif
#endif  // DMITIGR_THE_CPP_LIBRARY_NOMINMAX
