//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_LIMITEXPONENT_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_LIMITEXPONENT_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/brigand.hpp>
#include <boost/simd/detail/dispatch.hpp>
#include <boost/simd/detail/constant_traits.hpp>
#include <boost/dispatch/function/make_callable.hpp>
#include <boost/dispatch/hierarchy/functions.hpp>
#include <boost/dispatch/as.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    struct limitexponent_ : boost::dispatch::constant_value_<limitexponent_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,limitexponent_,boost::dispatch::constant_value_<limitexponent_>);

      struct value_map
      {
        template<typename X>
        static std::integral_constant<X,0> value(boost::dispatch::integer_<X> const&);

        template<typename X>
        static std::integral_constant<std::int32_t,128> value(boost::dispatch::single_<X> const&);

        template<typename X>
        static std::integral_constant<std::int64_t,1024> value(boost::dispatch::double_<X> const&);
      };
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,limitexponent_);
  }

  namespace detail
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::limitexponent_,limitexponent);
  }

  template<typename T> BOOST_FORCEINLINE auto Limitexponent()
  BOOST_NOEXCEPT_DECLTYPE(detail::limitexponent( boost::dispatch::as_<T>{}))
  {
    return detail::limitexponent( boost::dispatch::as_<T>{} );
  }
} }

#endif
