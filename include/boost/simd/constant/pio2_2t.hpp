//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_PIO2_2T_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_PIO2_2T_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-constant

    Constant used in modular computation involving \f$\pi\f$

    @par Semantic:

    For type T:

    @code
    T r = Pio2_2t<T>();
    @endcode

    @return a value of type T

**/
  template<typename T> T Pio2_2t();

  namespace functional
  {
    /*!
      @ingroup group-callable-constant


      Constant used in modular computation involving \f$\pi\f$

      Generate the  constant pio2_2t.

      @return The Pio2_2t constant for the proper type
    **/
    const boost::dispatch::functor<tag::pio2_2t_> pio2_2t = {};
  }
} }
#endif

#include <boost/simd/constant/definition/pio2_2t.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>
#include <boost/simd/arch/common/simd/constant/constant_value.hpp>

#endif
