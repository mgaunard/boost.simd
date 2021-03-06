//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/unary_plus.hpp>
#include <simd_test.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/two.hpp>

STF_CASE_TPL (" unary_plus real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::unary_plus;

  using r_t = decltype(unary_plus(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(unary_plus(bs::Inf<T>()), bs::Inf<r_t>());
  STF_EQUAL(unary_plus(bs::Minf<T>()), bs::Minf<r_t>());
  STF_IEEE_EQUAL(unary_plus(bs::Nan<T>()), bs::Nan<r_t>());
  STF_EQUAL(unary_plus(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(unary_plus(bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for floating_

STF_CASE_TPL (" unary_plus signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::unary_plus;
  using r_t = decltype(unary_plus(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(unary_plus(bs::Mone<T>()), bs::Mone<r_t>());
  STF_EQUAL(unary_plus(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(unary_plus(bs::Two<T>()), bs::Two<r_t>());
  STF_EQUAL(unary_plus(bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for signed_int_STF_CASE("unary_plus TO DO")


