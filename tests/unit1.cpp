// -*- C++ -*-
// Copyright (C) Dmitry Igrishin
// For conditions of distribution and use, see files LICENSE.txt or the_cpp_library.hpp

#include "unit.hpp"
#include "dmitigr/the_cpp_library.hpp"

#include <iostream>

namespace the_cpp_library = dmitigr::the_cpp_library;

int main(int, char**)
{
  try {
  } catch (const std::exception& e) {
    std::cerr << "error: " << e.what() << std::endl;
    return 1;
  } catch (...) {
    std::cerr << "unknown error" << std::endl;
    return 2;
  }
  return 0;
}
