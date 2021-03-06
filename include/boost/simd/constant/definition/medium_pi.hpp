//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_MEDIUM_PI_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_MEDIUM_PI_HPP_INCLUDED

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
    struct medium_pi_ : boost::dispatch::constant_value_<medium_pi_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,medium_pi_,boost::dispatch::constant_value_<medium_pi_>);
      BOOST_SIMD_REGISTER_CONSTANT(201, 0X43490FDB, 0X412921FB54442D18LL); //2^6/pi, //2^{18}/pi;
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,medium_pi_);
  }

  namespace detail
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::medium_pi_,medium_pi);
  }

  template<typename T> BOOST_FORCEINLINE auto Medium_pi()
  BOOST_NOEXCEPT_DECLTYPE(detail::medium_pi( boost::dispatch::as_<T>{}))
  {
    return detail::medium_pi( boost::dispatch::as_<T>{} );
  }
} }

#endif
