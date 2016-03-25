//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_POWER_VMX_SIMD_FUNCTION_BITWISE_ANDNOT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_POWER_VMX_SIMD_FUNCTION_BITWISE_ANDNOT_HPP_INCLUDED

#include <boost/simd/pack.hpp>
#include <boost/simd/sdk/meta/cardinal_of.hpp>
#include <boost/mpl/equal_to.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD_IF(bitwise_andnot_
                             , (typename A0, typename A1)
                             , bs::vmx_
                             , bs::pack_<bd::arithmetic_<A0>, bs::vmx_>
                             , bs::pack_<bd::arithmetic_<A1>, bs::vmx_>
                             )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0, const A0& a1) const BOOST_NOEXCEPT
      {
       return vec_andc(a0.storage(),simd::bitwise_cast<A0>(a1)());
      }
   };

} } }

#endif
#endif

