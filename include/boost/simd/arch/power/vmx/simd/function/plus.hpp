//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_POWER_VMX_SIMD_FUNCTION_PLUS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_POWER_VMX_SIMD_FUNCTION_PLUS_HPP_INCLUDED

#include <boost/simd/sdk/hierarchy/simd.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(plus_
                          , (typename A0)
                          , bs::vmx_
                          , bs::pack_<bd::arithmetic_<A0>, bs::vmx_>
                          , bs::pack_<bd::arithmetic_<A0>, bs::vmx_>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( ) const BOOST_NOEXCEPT
      {
       return vec_add(a0.storage(),a1.storage());
      }
   };

} } }

#endif
#endif

