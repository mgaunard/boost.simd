//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_ZERO_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_ZERO_HPP_INCLUDED

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
    struct zero_ : boost::dispatch::constant_value_<zero_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,zero_,boost::dispatch::constant_value_<zero_>);
      BOOST_SIMD_REGISTER_CONSTANT(0, 0x00000000UL, 0x0000000000000000ULL);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,zero_);
  }

  namespace detail
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::zero_,zero);
  }

  template<typename T> BOOST_FORCEINLINE auto Zero()
  BOOST_NOEXCEPT_DECLTYPE(detail::zero( boost::dispatch::as_<T>{}))
  {
    return detail::zero( boost::dispatch::as_<T>{} );
  }
} }

#endif
