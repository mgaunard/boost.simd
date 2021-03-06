//==================================================================================================
/*!
  @file

  Defines the as_logical meta-function

  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_META_AS_LOGICAL_HPP_INCLUDED
#define BOOST_SIMD_META_AS_LOGICAL_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/logical.hpp>
#include <boost/simd/meta/real_of.hpp>
#include <boost/simd/detail/brigand.hpp>
#include <boost/dispatch/meta/factory_of.hpp>
#include <boost/dispatch/meta/scalar_of.hpp>

namespace boost { namespace simd
{
  namespace details
  {
    template<typename T, typename F>
    struct  as_logical
    {
      using type = brigand::apply<F, logical<T> >;
    };

    template<typename T, typename F>
    struct  as_logical< logical<T>, F >
    {
      using type = brigand::apply<F, logical<T> >;
    };

    template<typename F>
    struct  as_logical<bool, F>
    {
      using type = brigand::apply<F, bool >;
    };
  }

  /*!
    @ingroup  group-api
    @brief    COnvert types to a logical type

    For a given type @c T , provides a type of same structure but able to fit a logical value.
    Provisions are taken so that conversion of logical and bool types is idempotent.

    @tparam T      Type to convert
  **/
  template<typename T>
  struct  as_logical
        : details::as_logical < real_of_t<T>
                              , dispatch::factory_of<T,dispatch::scalar_of_t<T>>
                              >
  {
  };

  /*!
    @ingroup  group-api
    @brief Eager short-cut to as_logical meta-function
  **/
  template<typename T> using as_logical_t = typename as_logical<T>::type;
} }

#endif
