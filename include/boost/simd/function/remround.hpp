//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_REMROUND_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_REMROUND_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!
    @ingroup group-arithmetic
    Function object implementing remround capabilities

    Computes the remainder of division.
    The return value is x-n*y, where n is the value x/y,
    rounded toward infinity.

    @par semantic:
    For any given value @c x, @c y of type @c T:

    @code
    T r = remround(x, y);
    @endcode

    For floating point values the code is equivalent to:

    @code
    T r = x-divround(x, y)*y;
    @endcode

  **/
  const boost::dispatch::functor<tag::remround_> remround = {};
} }
#endif

#include <boost/simd/function/scalar/remround.hpp>
#include <boost/simd/function/simd/remround.hpp>

#endif
