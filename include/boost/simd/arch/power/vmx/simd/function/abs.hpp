//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_POWER_VMX_SIMD_FUNCTION_ABS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_POWER_VMX_SIMD_FUNCTION_ABS_HPP_INCLUDED

#include <boost/simd/pack.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(abs_
                          , (typename A0)
                          , bs::vmx_
                          , bs::pack_<bd::single_<A0>, bs::vmx_>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( ) const BOOST_NOEXCEPT
      {
       return vec_abs( a0.storage() );
      }
   };

   BOOST_DISPATCH_OVERLOAD(abs_
                          , (typename A0)
                          , bs::vmx_
                          , bs::pack_<bd::signed_<A0>, bs::vmx_>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( ) const BOOST_NOEXCEPT
      {
       return vec_abs( a0.storage() );
      }
   };

} } }

#endif
#endif

