//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_SIGNIFICANTS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_SIGNIFICANTS_HPP_INCLUDED

#ifndef BOOST_SIMD_NO_INVALIDS
#include <boost/simd/function/scalar/if_else.hpp>
#include <boost/simd/function/scalar/is_invalid.hpp>
#endif
#include <boost/simd/function/scalar/abs.hpp>
#include <boost/simd/function/scalar/iceil.hpp>
#include <boost/simd/function/scalar/is_eqz.hpp>
#include <boost/simd/function/scalar/is_gtz.hpp>
#include <boost/simd/function/scalar/log10.hpp>
#include <boost/simd/function/scalar/minus.hpp>
#include <boost/simd/function/scalar/round.hpp>
#include <boost/simd/function/scalar/tenpower.hpp>
#include <boost/simd/detail/assert_utils.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/assert.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD ( significants_
                          , (typename A0, typename A1)
                          , bd::cpu_
                          , bd::scalar_< bd::floating_<A0>>
                          , bd::scalar_< bd::integer_<A1>>
                          )
  {

    BOOST_FORCEINLINE A0 operator() ( A0 a0, A1 a1) const BOOST_NOEXCEPT
    {
      BOOST_ASSERT_MSG( assert_all(is_gtz(a1))
                      , "Number of significant digits must be positive"
                      );
      using i_t = bd::as_integer_t<A0>;
      if (is_eqz(a0)) return a0;
      i_t exp = a1 - iceil(log10(abs(a0)));
      A0 fac = tenpower(exp);
      A0 scaled = round(a0*fac);
    #ifndef BOOST_SIMD_NO_INVALIDS
      return is_invalid(a0) ? a0 : scaled/fac;
    #else
      return scaled/fac;
    #endif
    }
  };
} } }


#endif
