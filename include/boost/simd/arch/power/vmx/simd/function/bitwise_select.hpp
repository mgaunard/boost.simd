//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_POWER_VMX_SIMD_FUNCTION_BITWISE_SELECT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_POWER_VMX_SIMD_FUNCTION_BITWISE_SELECT_HPP_INCLUDED

#include <boost/simd/sdk/hierarchy/simd.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <boost/simd/function/simd/bitwise_cast.hpp>
#include <boost/dispatch/meta/as_integer.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(bitwise_select_
                          , (typename A0, typename A1)
                          , bs::vmx_
                          , bs::pack_<bd::arithmetic_<A0>, bs::vmx_>
                          , bs::pack_<bd::arithmetic_<A1>, bs::vmx_>
                          , bs::pack_<bd::arithmetic_<A1>, bs::vmx_>
                          )
   {
      using result = ;
     inline result operator()(const A0& a0, const A1& a1, const A1&a2) const
      {
        using itype = bs::as_integer_t<A0, unsigned>;
       return vec_sel(a2.storage(), a1.storage(), bitwise_cast<itype>(a0)());
      }
   };


} } }

#endif

#endif

