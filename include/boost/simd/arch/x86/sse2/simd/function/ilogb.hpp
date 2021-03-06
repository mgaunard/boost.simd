//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS
    @copyright 2016 J.T.Lapreste

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_ILOGB_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_ILOGB_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/function/simd/bitwise_and.hpp>
#include <boost/simd/function/simd/bitwise_cast.hpp>
#include <boost/simd/function/simd/dec.hpp>
#include <boost/simd/function/simd/exponent.hpp>
#include <boost/simd/function/simd/group.hpp>
#include <boost/simd/function/simd/seladd.hpp>
#include <boost/simd/function/simd/split.hpp>
#include <boost/simd/function/simd/if_else.hpp>
#include <boost/simd/function/simd/if_zero_else.hpp>
#include <boost/simd/function/simd/is_eqz.hpp>
#include <boost/simd/function/simd/is_lez.hpp>
#include <boost/simd/function/simd/is_nez.hpp>
#include <boost/simd/function/simd/minus.hpp>
#include <boost/simd/function/simd/plus.hpp>
#include <boost/simd/function/simd/tofloat.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/constant.hpp>
#include <boost/simd/constant/zero.hpp>


namespace boost { namespace simd { namespace ext
{
  namespace bd =  boost::dispatch;
  namespace bs =  boost::simd;
  BOOST_DISPATCH_OVERLOAD ( ilogb_
                          , (typename A0)
                          , bs::sse2_
                          , bs::pack_<bd::int_<A0>, bs::sse_>
                         )
  {
    using result = bd::as_integer_t<A0>;
    BOOST_FORCEINLINE result operator() ( const A0 & a0)
    {
      using vtype = bd::as_integer_t<A0,unsigned>;
      return simd::bitwise_cast<A0>(if_zero_else( is_lez(a0)
                                                , ilogb(simd::bitwise_cast<vtype>(a0))
                                                )
                                   );
    }
  };
  BOOST_DISPATCH_OVERLOAD ( ilogb_
                          , (typename A0)
                          , bs::sse2_
                          , bs::pack_<bd::uint8_<A0>, bs::sse_>
                          )
  {

    BOOST_FORCEINLINE A0 operator() ( const A0 & a0)
    {
#define MKN8 simd::bitwise_cast<A0>
      const A0 mask =  Constant<A0, 0x7f>();
      A0 n = a0;
      A0 i = One<A0>();
      n = bitwise_and(MKN8(_mm_srli_epi16(n, 1)), mask);
      i = seladd(is_nez(n), i, One<A0>());
      n = bitwise_and(MKN8(_mm_srli_epi16(n, 1)), mask);
      i = seladd(is_nez(n), i, One<A0>());
      n = bitwise_and(MKN8(_mm_srli_epi16(n, 1)), mask);
      i = seladd(is_nez(n), i, One<A0>());
      n = bitwise_and(MKN8(_mm_srli_epi16(n, 1)), mask);
      i = seladd(is_nez(n), i, One<A0>());
      n = bitwise_and(MKN8(_mm_srli_epi16(n, 1)), mask);
      i = seladd(is_nez(n), i, One<A0>());
      n = bitwise_and(MKN8(_mm_srli_epi16(n, 1)), mask);
      i = seladd(is_nez(n), i, One<A0>());
      n = bitwise_and(MKN8(_mm_srli_epi16(n, 1)), mask);
      i = seladd(is_nez(n), i, One<A0>());
      return dec(i);
    }
#undef MKN8
  };

  BOOST_DISPATCH_OVERLOAD ( ilogb_
                          , (typename A0)
                          , bs::sse2_
                          , bs::pack_<bd::uint16_<A0>, bs::sse_>
                          )
  {
    using result = bd::as_integer_t<A0>;
    BOOST_FORCEINLINE result operator() ( const A0 & a0)
    {
      using up_t = detail::make_dependent_t<int32_t,A0>;
      using gen_t = pack<up_t, 32>;//this is not correct TODO using new upgrade possibilities
      gen_t a0h, a0l;
      split(a0, a0l, a0h);
      return group(ilogb(a0l), ilogb(a0h));
    }
  };
  BOOST_DISPATCH_OVERLOAD ( ilogb_
                          , (typename A0)
                          , bs::sse2_
                          , bs::pack_<bd::unsigned_<A0>, bs::sse_>
                          )
  {
    using result = bd::as_integer_t<A0>;
    BOOST_FORCEINLINE result operator() ( const A0 & a0)
    {
      return simd::bitwise_cast<A0>(bs::exponent(tofloat(a0)));
    }
  };
} } }

#endif
