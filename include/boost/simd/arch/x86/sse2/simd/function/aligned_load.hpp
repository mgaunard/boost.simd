//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_ALIGNED_LOAD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_ALIGNED_LOAD_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/dispatch/adapted/common/pointer.hpp>
#include <boost/align/is_aligned.hpp>
#include <boost/assert.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = ::boost::dispatch;
  namespace bs = ::boost::simd;

  //------------------------------------------------------------------------------------------------
  // load from an aligned pointer of double
  BOOST_DISPATCH_OVERLOAD ( aligned_load_
                          , (typename Target, typename Pointer)
                          , bs::sse2_
                          , bd::pointer_<bd::scalar_<bd::double_<Pointer>>,1u>
                          , bd::target_<bs::pack_<bd::double_<Target>,bs::sse_>>
                          )
  {
    using target = typename Target::type;
    BOOST_FORCEINLINE target operator()(Pointer p, Target const&) const
    {
      BOOST_ASSERT_MSG( boost::alignment::is_aligned(target::alignment, p)
                      , "boost::simd::aligned_load was performed on an unaligned pointer of double"
                      );

      return _mm_load_pd(p);
    }
  };

  //------------------------------------------------------------------------------------------------
  // load from an aligned pointer of integer
  BOOST_DISPATCH_OVERLOAD ( aligned_load_
                          , (typename Target, typename Pointer)
                          , bs::sse2_
                          , bd::pointer_<bd::scalar_<bd::integer_<Pointer>>,1u>
                          , bd::target_<bs::pack_<bd::integer_<Target>,bs::sse_>>
                          )
  {
    using target  = typename Target::type;

    BOOST_FORCEINLINE target operator() ( Pointer p, Target const& ) const
    {
      BOOST_ASSERT_MSG( boost::alignment::is_aligned(target::alignment, p)
                      , "boost::simd::aligned_load was performed on an unaligned pointer of integer"
                      );

      return _mm_load_si128( (__m128i*)(p) );
    }
  };

} } }

#endif
