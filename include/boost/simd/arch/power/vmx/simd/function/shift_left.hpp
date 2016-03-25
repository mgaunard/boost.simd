//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_POWER_VMX_SIMD_FUNCTION_SHIFT_LEFT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_POWER_VMX_SIMD_FUNCTION_SHIFT_LEFT_HPP_INCLUDED

#include <boost/simd/pack.hpp>
#include <boost/simd/operator/function/details/assert_utils.hpp>
#include <boost/simd/function/simd/bitwise_cast.hpp>
#include <boost/simd/function/simd/splat.hpp>
#include <boost/assert.hpp>
#include <boost/dispatch/meta/as_unsigned.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(shift_left_
                          , (typename A0, typename A1)
                          , bs::vmx_
                          , bs::pack_<bd::integer_<A0>, bs::vmx_>
                          , bs::pack_<bd::integer_<A1>, bs::vmx_>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0, const A0& a1) const BOOST_NOEXCEPT
      {
        using type = bs::as_unsigned_t<A1>;
       BOOST_ASSERT_MSG( assert_good_shift<A0>(a1)
                        , "shift_left: a shift is out of range"
                        );
       return vec_sl(a0.storage(), simd::bitwise_cast<type>(a1)());
      }
   };

   BOOST_DISPATCH_OVERLOAD(shift_left_
                          , (typename A0, typename A1)
                          , bs::vmx_
                          , bs::pack_<bd::integer_<A0>, bs::vmx_>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0, const A0& a1) const BOOST_NOEXCEPT
      {
       BOOST_ASSERT_MSG( assert_good_shift<A0>(a1)
                        , "shift_left: a shift is out of range"
                        );
       return a0 << splat<A0>(a1);
      }
   };

} } }

#endif
#endif

