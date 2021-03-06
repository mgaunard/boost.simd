//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_EULERIAN_HPP_INCLUDED
#define BOOST_SIMD_EULERIAN_HPP_INCLUDED

namespace boost { namespace simd
{
  /*!
    @ingroup group-functions
    @defgroup group-euler Eulerian functions

    Algorithms for computing scalar and SIMD version of
    some eulerian functions. Mainly those that are present in
    stdlibc++ 11.

  **/

  /*!
    @ingroup group-callable
    @defgroup group-callable-euler Eulerian Callable Objects
    Callable objects version of @ref group-euler

    Their specific semantic limitations are similar to those of their function
    equivalents as described in the @ref group-euler section.
  **/
} }

#include <boost/simd/function/erfc.hpp>
#include <boost/simd/function/erfcx.hpp>
#include <boost/simd/function/erf.hpp>
#include <boost/simd/function/gamma.hpp>
#include <boost/simd/function/gammaln.hpp>
#include <boost/simd/function/signgam.hpp>
#include <boost/simd/function/stirling.hpp>

#endif
