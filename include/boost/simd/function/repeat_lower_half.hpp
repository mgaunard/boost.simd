//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_REPEAT_LOWER_HALF_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_REPEAT_LOWER_HALF_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-swar
    Function object implementing repeat_lower_half capabilities

    Repeat lower half of a vector

    @par Semantic:

    For every parameter of type T

    @code
    T r = repeat_lower_half(x);
    @endcode

    is similar to:

    @code
      T r;
      const std::size_t  middle = meta::cardinal_of<A0>::value/2;
      for(std::size_t i=0;i<middle;++i)
      {
        r[i] = r[i+middle] = x[i];
      }
    @endcode

  **/
  const boost::dispatch::functor<tag::repeat_lower_half_> repeat_lower_half = {};
} }
#endif

#include <boost/simd/function/scalar/repeat_lower_half.hpp>
#include <boost/simd/function/simd/repeat_lower_half.hpp>

#endif
