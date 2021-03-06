//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_COMPARE_NEQ_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_COMPARE_NEQ_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-reduction
    Function object implementing compare_neq capabilities

    Returns a logical scalar that is the result of the lexicographic
    test for != on elements of the entries,
    i.e. return @ref True if and only if two corresponding entries
    elements are not equal.

    It is probably not what you wish. Have a look to @ref is_not_equal

    This is a convenient alias of @ref compare_not_equal
  **/
  const boost::dispatch::functor<tag::compare_neq_> compare_neq = {};
} }
#endif

#include <boost/simd/function/scalar/compare_not_equal.hpp>
#include <boost/simd/function/simd/compare_neq.hpp>

#endif
