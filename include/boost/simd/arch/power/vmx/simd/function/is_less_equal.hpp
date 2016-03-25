//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_POWER_VMX_SIMD_FUNCTION_IS_LESS_EQUAL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_POWER_VMX_SIMD_FUNCTION_IS_LESS_EQUAL_HPP_INCLUDED

#include <boost/simd/pack.hpp>
#include <boost/simd/sdk/as_logical.hpp>
#include <boost/simd/function/simd/logical_not.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(is_less_equal_
                          , (typename A0)
                          , bs::vmx_
                          , bs::pack_<bd::floating_<A0>, bs::vmx_>
                          , bs::pack_<bd::floating_<A0>, bs::vmx_>
                          )
   {
      using result = bs::as_logical_t<A0>;
      BOOST_FORCEINLINE result operator()( ) const BOOST_NOEXCEPT
      {
       return vec_cmple(a0.storage(),a1.storage());
      }
   };

   BOOST_DISPATCH_OVERLOAD(is_less_equal_
                          , (typename A0)
                          , bs::vmx_
                          , bs::pack_<bd::integer_<A0>, bs::vmx_>
                          , bs::pack_<bd::integer_<A0>, bs::vmx_>
                          )
   {
      using result = bs::as_logical_t<A0>;
      BOOST_FORCEINLINE result operator()( ) const BOOST_NOEXCEPT
      {
       result lt = vec_cmpgt(a0.storage(),a1.storage());
        return !lt;
      }
   };

} } }

#endif
#endif

