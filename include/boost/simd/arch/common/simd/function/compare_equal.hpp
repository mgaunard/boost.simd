//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_COMPARE_EQUAL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_COMPARE_EQUAL_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/logical.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(compare_equal_
                          , (typename A0,typename X)
                          , bd::cpu_
                          , bs::pack_<bd::arithmetic_<A0>,X>
                          , bs::pack_<bd::arithmetic_<A0>,X>
                          )

  {
    using sA0 =  bd::scalar_of_t<A0>;
    BOOST_FORCEINLINE logical<sA0> operator()( const A0& a0, const A0& a1) const BOOST_NOEXCEPT
    {
      for(unsigned int i=0; i < A0::static_size; ++i)
      {
        if (a0[i] != a1[i]) return {false};
      }
      return {true};
    }

  };

} } }

#endif

