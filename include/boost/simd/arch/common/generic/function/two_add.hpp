//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_TWO_ADD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_TWO_ADD_HPP_INCLUDED

#include <boost/simd/detail/enforce_precision.hpp>
#include <boost/simd/function/simd/if_zero_else.hpp>
#include <boost/simd/function/simd/is_inf.hpp>
#include <boost/simd/function/simd/minus.hpp>
#include <boost/simd/function/simd/plus.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <utility>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;

  BOOST_DISPATCH_OVERLOAD ( two_add_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::floating_<A0> >
                          , bd::generic_< bd::floating_<A0> >
                          )
  {
    using result_t = std::pair<A0,A0>                                  ;

    BOOST_FORCEINLINE result_t operator() ( A0 const& a,A0 const& b) const BOOST_NOEXCEPT
    {
      detail::enforce_precision<A0> enforcer;
      A0 r0 = a  + b;
      A0 z = r0 - a;
#if defined(BOOST_SIMD_NO_INFINITIES)
      A0 r1 = a-(r0-z)+(b-z);
#else
      A0 r1 = if_zero_else(is_inf(r0), (a-(r0-z))+(b-z));
#endif
      return {r0, r1};
    }
  };
} } }


#endif
