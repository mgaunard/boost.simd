//==================================================================================================
/**
  Copyright 2016 NumScale SAS
  Copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DEFINITION_GROUP_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DEFINITION_GROUP_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/dispatch/function/make_callable.hpp>
#include <boost/dispatch/hierarchy/functions.hpp>
#include <boost/simd/detail/dispatch.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    BOOST_DISPATCH_MAKE_TAG(ext, group_, boost::dispatch::abstract_<group_>);
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag, group_);
  }

  BOOST_DISPATCH_CALLABLE_DEFINITION(tag::group_,group);
} }

#endif
