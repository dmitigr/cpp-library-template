// -*- C++ -*-
// Copyright (C) Dmitry Igrishin
// For conditions of distribution and use, see files LICENSE.txt or the_cpp_library.hpp

#ifndef DMITIGR_THE_CPP_LIBRARY_DEBUG_HPP
#define DMITIGR_THE_CPP_LIBRARY_DEBUG_HPP

#include "dmitigr/internal/debug.hpp"

namespace dmitigr::the_cpp_library::detail {

class Runtime_exception : public internal::debug::Runtime_error {
public:
  Runtime_exception(std::string_view cl_or_fn, std::string_view message)
    : Runtime_error{"dmitigr::the_cpp_library", cl_or_fn, message}
  {}
};

template<class E, typename T>
inline void require(const T& req, const char* const fn, const char* const details = nullptr)
{
  internal::debug::require<E>(req, "dmitigr::the_cpp_library", fn, details);
}

template<class E, typename T>
inline void require(const T& req, const char* const cl, const char* const fn, const char* const details)
{
  internal::debug::require<E>(req, "dmitigr::the_cpp_library", cl, fn, details);
}

} // namespace dmitigr::the_cpp_library::detail

#endif  // DMITIGR_THE_CPP_LIBRARY_DEBUG_HPP
