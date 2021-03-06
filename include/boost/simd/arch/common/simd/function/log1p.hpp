//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_LOG1P_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_LOG1P_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/function/simd/divides.hpp>
#include <boost/simd/function/simd/is_nez.hpp>
#include <boost/simd/function/simd/log.hpp>
#include <boost/simd/function/simd/minus.hpp>
#include <boost/simd/function/simd/minusone.hpp>
#include <boost/simd/function/simd/oneplus.hpp>
#include <boost/simd/function/simd/seladd.hpp>

#ifndef BOOST_SIMD_NO_INFINITIES
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/function/simd/if_else.hpp>
#include <boost/simd/function/simd/is_equal.hpp>
#endif

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;

  BOOST_DISPATCH_OVERLOAD ( log1p_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator()( const A0& a0) BOOST_NOEXCEPT
    {
      A0 u = oneplus(a0);
      A0 r = seladd(is_nez(u),
                    log(u),
                    (a0-minusone(u))/u); // cancels errors with IEEE arithmetic
#ifndef BOOST_SIMD_NO_INFINITIES
      r = if_else(is_equal(u, Inf<A0>()),u, r);
#endif
      return r;
    }
  };
} } }

#endif
