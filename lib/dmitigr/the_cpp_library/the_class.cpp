// -*- C++ -*-
// Copyright (C) Dmitry Igrishin
// For conditions of distribution and use, see files LICENSE.txt or the_cpp_library.hpp

#include "dmitigr/the_cpp_library/debug.hpp"
#include "dmitigr/the_cpp_library/the_class.hpp"

#include "dmitigr/the_cpp_library/implementation_header.hpp"

namespace dmitigr::the_cpp_library {

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

DMITIGR_THE_CPP_LIBRARY_INLINE std::unique_ptr<The_class> The_class::make()
{
  return std::make_unique<iThe_class>();
}

} // namespace dmitigr::the_cpp_library

#include "dmitigr/the_cpp_library/implementation_footer.hpp"
