//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_POWER_VMX_SIMD_FUNCTION_ALL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_POWER_VMX_SIMD_FUNCTION_ALL_HPP_INCLUDED

#include <boost/simd/sdk/hierarchy/simd.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <boost/simd/sdk/as_logical.hpp>
#include <boost/simd/constant/true.hpp>
#include <boost/simd/function/simd/is_nez.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(all_
                          , (typename A0)
                          , bs::vmx_
                          , bs::pack_<bd::arithmetic_<A0>, bs::vmx_>
                          )
   {
      using result = bs::as_logical_t<typename A0::value_type>;
      BOOST_FORCEINLINE result operator()( ) const BOOST_NOEXCEPT
      {
       return bs::all( is_nez(a0) );
      }
   };

   BOOST_DISPATCH_OVERLOAD(all_
                          , (typename A0)
                          , bs::vmx_
                          , bs::pack_<bs::logical_<A0>, bs::vmx_>
                          )
   {
      using result = bs::as_logical_t<typename A0::value_type>;
      BOOST_FORCEINLINE result operator()( ) const BOOST_NOEXCEPT
      {
       return result( vec_all_eq( a0.storage(), True<A0>()() ) );
      }
   };

} } }

#endif
#endif

