//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_UNORD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_UNORD_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-predicates
    Function object implementing is_unord capabilities

    Returns @ref True if x or y is nan.

    @par Semantic:

    @code
    as_logical_t<T> r = is_unord(x,y);
    @endcode

    is similar to:

    @code
    as_logical_t<T> r = (x != x) || (y != y);
    @endcode

  **/
  const boost::dispatch::functor<tag::is_unord_> is_unord = {};
} }
#endif

#include <boost/simd/function/scalar/is_unord.hpp>
#include <boost/simd/function/simd/is_unord.hpp>

#endif
