// -*- C++ -*-
// Copyright (C) Dmitry Igrishin
// For conditions of distribution and use, see files LICENSE.txt or the_cpp_library.hpp

#ifndef DMITIGR_THE_CPP_LIBRARY_TYPES_FWD_HPP
#define DMITIGR_THE_CPP_LIBRARY_TYPES_FWD_HPP

/**
 * @brief Public API.
 *
 * @warning The nested namespaces `detail` contains implementation details
 * which are should not be used in applications.
 */
namespace dmitigr::the_cpp_library {

/**
 * @defgroup main Main
 */

// -----------------------------------------------------------------------------
// Classes
// -----------------------------------------------------------------------------

class The_class;

/**
 * @brief The namespace dmitigr::the_cpp_library::ic contains implementation classes. These
 * classes can be used when header-only `dmitigr::the_cpp_library` library is in use.
 */
namespace ic {

class iThe_class;

} // namespace ic

} // namespace dmitigr::the_cpp_library

#endif  // DMITIGR_THE_CPP_LIBRARY_TYPES_FWD_HPP
