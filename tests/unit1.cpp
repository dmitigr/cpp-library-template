// -*- C++ -*-
// Copyright (C) Dmitry Igrishin
// For conditions of distribution and use, see files LICENSE.txt or the_cpp_library.hpp

#include "unit.hpp"
#include "dmitigr/the_cpp_library.hpp"

#include <iostream>

namespace the_cpp_library = dmitigr::the_cpp_library;
namespace internal = dmitigr::internal;

int main(int, char**)
{
  try {
  } catch (const std::exception& e) {
    std::cout << "error: " << e.what() << std::endl;
    return 1;
  } catch (...) {
    std::cout << "unknown error" << std::endl;
    return 2;
  }
  return 0;
}
