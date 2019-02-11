// -*- C++ -*-
// Copyright (C) Dmitry Igrishin
// For conditions of distribution and use, see files LICENSE.txt or the_cpp_library.hpp

#ifndef DMITIGR_THE_CPP_LIBRARY_THE_CLASS_CPP
#define DMITIGR_THE_CPP_LIBRARY_THE_CLASS_CPP

#include "dmitigr/internal/debug.hpp"
#include "dmitigr/the_cpp_library/header_only.hpp"
#include "dmitigr/the_cpp_library/the_class.hpp"

namespace dmitigr::the_cpp_library::ic {

class iThe_class final : public The_class {
public:
  explicit iThe_class()
  {
    DMITIGR_INTERNAL_ASSERT(is_invariant_ok());
  }

private:
  bool is_invariant_ok() const
  {
    return true;
  }
};

} // namespace dmitigr::the_cpp_library::ic

namespace dmitigr::the_cpp_library {

DMITIGR_THE_CPP_LIBRARY_API std::unique_ptr<The_class> The_class::make()
{
  return std::make_unique<ic::iThe_class>();
}

} // namespace dmitigr::the_cpp_library

#endif  // DMITIGR_THE_CPP_LIBRARY_THE_CLASS_CPP
