// -*- C++ -*-
// Copyright (C) Dmitry Igrishin
// For conditions of distribution and use, see files LICENSE.txt or the_cpp_library.hpp

#ifndef DMITIGR_THE_CPP_LIBRARY_THE_CLASS_HPP
#define DMITIGR_THE_CPP_LIBRARY_THE_CLASS_HPP

#include "dmitigr/the_cpp_library/dll.hpp"
#include "dmitigr/the_cpp_library/types_fwd.hpp"

#include <memory>

namespace dmitigr::the_cpp_library {

/**
 * @brief Defines an abstraction of a ...
 */
class The_class {
public:
  /**
   * @brief The destructor.
   */
  virtual ~The_class() = default;

  /// @name Constructors
  /// @{

  /**
   * @brief Constructs the object ...
   */
  static DMITIGR_THE_CPP_LIBRARY_API std::unique_ptr<The_class> make();

  /// @}

  /// @name Observers
  /// @{
  /// @}

  // ---------------------------------------------------------------------------

  /// @name Modifiers
  /// @{
  /// @}

  // ---------------------------------------------------------------------------

  /// @name Conversions
  /// @{
  /// @}
private:
  friend iThe_class;

  The_class() = default;
};

} // namespace dmitigr::the_cpp_library

#ifdef DMITIGR_THE_CPP_LIBRARY_HEADER_ONLY
#include "dmitigr/the_cpp_library/the_class.cpp"
#endif

#endif  // DMITIGR_THE_CPP_LIBRARY_THE_CLASS_HPP
