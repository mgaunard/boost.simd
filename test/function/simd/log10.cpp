//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS
  Copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/log10.hpp>
#include <boost/simd/function/rec.hpp>
#include <boost/simd/function/std.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  T a1[N], b[N], c[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : bs::rec(T(i));
    b[i] = bs::log10(a1[i]) ;
    c[i] = bs::std_(bs::log10)(a1[i]) ;
  }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);
  p_t cc (&c[0], &c[0]+N);
  std::cout << "aa1 " << aa1 << std::endl;
  STF_ULP_EQUAL(bb, cc, 0.5);
  STF_IEEE_EQUAL(bs::log10(aa1), bb);
  STF_IEEE_EQUAL(bs::std_(bs::log10)(aa1), cc);
}

STF_CASE_TPL("Check log10 on pack", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}
