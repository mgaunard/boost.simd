//==================================================================================================
/**
  Copyright 2016 NumScale SAS
  Copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SIMD_INTERLEAVE_SECOND_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SIMD_INTERLEAVE_SECOND_HPP_INCLUDED

#include <boost/simd/function/definition/interleave_second.hpp>
#include <boost/simd/arch/common/simd/function/interleave_second.hpp>

#if defined(BOOST_HW_SIMD_X86)
#  if BOOST_HW_SIMD_X86 >= BOOST_HW_SIMD_X86_SSE_VERSION
#    include <boost/simd/arch/x86/sse1/simd/function/interleave_second.hpp>
#  endif
#  if BOOST_HW_SIMD_X86 >= BOOST_HW_SIMD_X86_SSE2_VERSION
#    include <boost/simd/arch/x86/sse2/simd/function/interleave_second.hpp>
#  endif
#  if BOOST_HW_SIMD_X86 >= BOOST_HW_SIMD_X86_AVX_VERSION
#    include <boost/simd/arch/x86/avx/simd/function/interleave_second.hpp>
#  endif
#  if BOOST_HW_SIMD_X86 >= BOOST_HW_SIMD_X86_AVX2_VERSION
#    include <boost/simd/arch/x86/avx2/simd/function/interleave_second.hpp>
#  endif
#endif

#if defined(BOOST_HW_SIMD_PPC)
#  if BOOST_HW_SIMD_PPC >= BOOST_HW_SIMD_PPC_VMX_VERSION
// #    include <boost/simd/arch/power/vmx/simd/function/interleave_second.hpp>
#  endif
#endif

#endif
