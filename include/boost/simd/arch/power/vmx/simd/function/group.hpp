//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_POWER_VMX_SIMD_FUNCTION_GROUP_HPP_INCLUDED
#define BOOST_SIMD_ARCH_POWER_VMX_SIMD_FUNCTION_GROUP_HPP_INCLUDED

#include <boost/simd/pack.hpp>
#include <boost/dispatch/meta/downgrade.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(group_
                          , (typename A0)
                          , bs::vmx_
                          , bs::pack_<bd::ints32_<A0>, bs::vmx_>
                          , bs::pack_<bd::ints32_<A0>, bs::vmx_>
                          )
   {
      using result = bd::downgrade_t<A0>;
      BOOST_FORCEINLINE result operator()( ) const BOOST_NOEXCEPT
      {
       return vec_pack(a0.storage(), a1.storage());
      }
   };

   BOOST_DISPATCH_OVERLOAD(group_
                          , (typename A0)
                          , bs::vmx_
                          , bs::pack_<bd::ints16_<A0>, bs::vmx_>
                          , bs::pack_<bd::ints16_<A0>, bs::vmx_>
                          )
   {
      using result = bd::downgrade_t<A0>;
      BOOST_FORCEINLINE result operator()( ) const BOOST_NOEXCEPT
      {
       return vec_pack(a0.storage(), a1.storage());
      }
   };

} } }

#endif
#endif

