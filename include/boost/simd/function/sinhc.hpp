//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SINHC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SINHC_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-hyperbolic
    Function object implementing sinhc capabilities

    Returns hyperbolic cardinal sine: \f$\frac{\sinh(x)}{x}\f$.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = sinhc(x);
    @endcode

    is similar to:

    @code
    T r = sinh(x)/x;
    @endcode

    @see sinh

  **/
  const boost::dispatch::functor<tag::sinhc_> sinhc = {};
} }
#endif

#include <boost/simd/function/scalar/sinhc.hpp>
#include <boost/simd/function/simd/sinhc.hpp>

#endif
