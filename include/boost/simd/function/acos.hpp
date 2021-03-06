//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ACOS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ACOS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-trigonometric
    Function object implementing acos capabilities

    inverse cosine in radian.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = acos(x);
    @endcode

    Returns the arc @c r in the interval
    \f$[0, \pi[\f$ such that <tt>cos(r) == x</tt>.
    If @c x is outside \f$[-1, 1[\f$ the result is Nan.

    @par Decorators

    std_ for floating entries

    @see acosd, acospi

  **/
  const boost::dispatch::functor<tag::acos_> acos = {};
} }
#endif

#include <boost/simd/function/scalar/acos.hpp>
#include <boost/simd/function/simd/acos.hpp>

#endif
