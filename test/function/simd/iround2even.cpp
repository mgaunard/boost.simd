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
#include <boost/simd/function/iround2even.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <simd_test.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using p_t = bs::pack<T, N>;
  using iT =  bd::as_integer_t<T>;
  using pi_t = bs::pack<iT, N>;

  T a1[N];
  iT b[N], c[N];
  for(std::size_t i = 0; i < N; ++i)
  {
     a1[i] = T(i+1);
     b[i] = bs::fast_(bs::iround2even)(a1[i]);
     c[i] = bs::iround2even(a1[i]);
   }
  p_t aa1(&a1[0], &a1[0]+N);
  pi_t bb(&b[0], &b[0]+N);
  pi_t cc(&c[0], &c[0]+N);
  STF_EQUAL(bs::fast_(bs::iround2even)(aa1), bb);
  STF_EQUAL(bs::iround2even(aa1), cc);
}

STF_CASE_TPL("Check iround2even on pack", STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

