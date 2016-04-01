//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_POWER_VMX_SIMD_FUNCTION_TOFLOAT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_POWER_VMX_SIMD_FUNCTION_TOFLOAT_HPP_INCLUDED

#include <boost/simd/sdk/hierarchy/simd.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <boost/dispatch/meta/as_floating.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(tofloat_
                          , (typename A0)
                          , bs::vmx_
                          , bs::pack_<bd::ints32_<A0>, bs::vmx_>
                          )
   {
      using result = bs::as_floating_t<A0>;
      BOOST_FORCEINLINE result operator()( ) const BOOST_NOEXCEPT
      {
       return vec_ctf(a0.storage(),0);
      }
   };

} } }

#endif
#endif

