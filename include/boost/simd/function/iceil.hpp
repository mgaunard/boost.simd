//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ICEIL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ICEIL_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-arithmetic
    Function object implementing iceil capabilities

    Computes the integer conversion of the ceil of its parameter.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    as_integer_t<T> r = iceil(x);
    @endcode

    is equivalent to:

    @code
    as_integer_t<T> r = toint_s(ceil(x));
    @endcode

    @par Note:
    This operation is properly saturated

  **/
  const boost::dispatch::functor<tag::iceil_> iceil = {};
} }
#endif

#include <boost/simd/function/scalar/iceil.hpp>
#include <boost/simd/function/simd/iceil.hpp>

#endif
