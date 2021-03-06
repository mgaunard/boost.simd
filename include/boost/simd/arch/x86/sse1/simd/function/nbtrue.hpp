//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS
    @copyright 2016 J.T.Lapreste

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_NBTRUE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_NBTRUE_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/simd/inbtrue.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd =  boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( nbtrue_
                          , (typename A0)
                          , bs::sse_
                          , bs::pack_<bd::single_<A0>, bs::sse_>
                         )
  {
    BOOST_FORCEINLINE float operator() ( const A0 & a0 ) const BOOST_NOEXCEPT
    {
      return  float(inbtrue(a0));

   }
  };
} } }

#endif

