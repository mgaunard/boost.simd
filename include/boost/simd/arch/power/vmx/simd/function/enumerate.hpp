//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_POWER_VMX_SIMD_FUNCTION_ENUMERATE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_POWER_VMX_SIMD_FUNCTION_ENUMERATE_HPP_INCLUDED

#include <boost/simd/sdk/hierarchy/simd.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <boost/simd/function/simd/bitwise_cast.hpp>
#include <boost/simd/function/simd/make.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(enumerate_
                          , bs::vmx_
                          , bs::pack_<bd::ints8_<T>, bs::vmx_>
                          )
   {
      using result = T;
     BOOST_FORCEINLINE result operator()(T const& ) const
      {
        using u8type = result::template rebind<unsigned char>;
        // [0 1 2 ... 12 15]
        u8type that = vec_lvsl(0,(unsigned char*)(0));
        return bitwise_cast<result>(that);
      }
   };

} } }

#endif
#endif

