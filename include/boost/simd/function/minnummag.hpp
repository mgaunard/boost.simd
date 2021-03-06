//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MINNUMMAG_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MINNUMMAG_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-ieee
    Function object implementing minnummag capabilities

    Returns the input value which have the least absolute value, ignoring nan.

    @par Semantic:

    @code
    T r = minnummag(x,y);
    @endcode

    is similar to:

    @code
    T r =  isnan(x) ? y : (isnan(y) ? x : minmag(x, y));;
    @endcode

    @see min, minnum, minmag

  **/
  const boost::dispatch::functor<tag::minnummag_> minnummag = {};
} }
#endif

#include <boost/simd/function/scalar/minnummag.hpp>
#include <boost/simd/function/simd/minnummag.hpp>

#endif
