//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_PIX2_1_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_PIX2_1_HPP_INCLUDED

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
    struct pix2_1_ : boost::dispatch::constant_value_<pix2_1_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,pix2_1_,boost::dispatch::constant_value_<pix2_1_>);
      BOOST_SIMD_REGISTER_CONSTANT(1, 0X40C90F00, 0X401921FB54400000LL);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,pix2_1_);
  }

  namespace detail
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::pix2_1_,pix2_1);
  }

  template<typename T> BOOST_FORCEINLINE auto Pix2_1()
  BOOST_NOEXCEPT_DECLTYPE(detail::pix2_1( boost::dispatch::as_<T>{}))
  {
    return detail::pix2_1( boost::dispatch::as_<T>{} );
  }
} }

#endif
