//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_TOINT_S_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_TOINT_S_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/config.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/function/simd/bitwise_cast.hpp>
#include <boost/simd/function/simd/if_else.hpp>
#include <boost/simd/function/simd/is_greater_equal.hpp>
#include <boost/simd/function/simd/is_less_equal.hpp>
#include <boost/simd/function/simd/saturate.hpp>
#include <boost/simd/function/simd/splat.hpp>
#include <boost/simd/function/simd/toint.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/dispatch/meta/scalar_of.hpp>

#ifndef BOOST_SIMD_NO_NANS
#include <boost/simd/function/simd/if_zero_else.hpp>
#include <boost/simd/function/simd/is_nan.hpp>
#endif

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(toint_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::saturated_tag
                          , bs::pack_<bd::uint_<A0>, X>
                          )
   {
     using result = bd::as_integer_t<A0, signed>;
     BOOST_FORCEINLINE result operator()(const saturated_tag &
                                        , A0 const& a0) const
      {
        return bitwise_cast<result>(saturate<result>(a0));
      }
   };

   BOOST_DISPATCH_OVERLOAD(toint_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::saturated_tag
                          , bs::pack_<bd::int_<A0>, X>
                          )
   {
     BOOST_FORCEINLINE A0 operator()(const saturated_tag &
                                    , A0 const& a0) const
      {
        return a0;
      }
   };

   BOOST_DISPATCH_OVERLOAD(toint_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::saturated_tag
                          , bs::pack_<bd::floating_<A0>, X>
                          )
   {
      using result = bd::as_integer_t<A0>;
      BOOST_FORCEINLINE result operator()(const saturated_tag &
                                         ,  const A0& a0) const BOOST_NOEXCEPT
      {
        using sr_t = bd::scalar_of_t<result>;
        const A0 Vax = splat<A0>(bs::Valmax<sr_t>());
        const A0 Vix = splat<A0>(bs::Valmin<sr_t>());
      #ifndef BOOST_SIMD_NO_NANS
        A0 aa0 = if_zero_else(is_nan(a0), a0);
        return if_else(bs::is_less_equal(aa0, Vix), Valmin<result>(),
                       if_else(bs::is_greater_equal(aa0, Vax), Valmax<result>(),
                               toint(aa0)
                              )
                      );
      #else
        return if_else(bs::is_less_equal(a0, Vix), Valmin<result>(),
                       if_else(bs::is_greater_equal(a0, Vax), Valmax<result>(),
                               toint(a0)
                              )
                      );
      #endif
      }
   };

} } }

#endif

