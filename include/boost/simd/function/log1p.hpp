//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_LOG1P_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LOG1P_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!
  @ingroup group-trigonometry
    Function object implementing log1p capabilities

    Computes log1p value of its parameter.

  **/
  const boost::dispatch::functor<tag::log1p_> log1p = {};
} }
#endif

#include <boost/simd/function/scalar/log1p.hpp>
#include <boost/simd/function/simd/log1p.hpp>

#endif
