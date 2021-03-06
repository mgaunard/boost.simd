//==================================================================================================
/*!
  @file

  Defines the SIMD storage meta-generator

  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_DETAIL_STORAGE_OF_HPP_INCLUDED
#define BOOST_SIMD_DETAIL_STORAGE_OF_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/forward.hpp>
#include <boost/simd/detail/as_simd.hpp>
#include <boost/simd/meta/expected_cardinal.hpp>
#include <boost/simd/detail/brigand.hpp>
#include <type_traits>
#include <array>

namespace boost { namespace simd { namespace detail
{
  // Status for emulated SIMD storage via array of scalar
  using emulated_status   = brigand::int32_t<-1>;

  // Status for native SIMD storage
  using native_status     = brigand::int32_t<+0>;

  // Status for emulated SIMD storage via array of pack
  using aggregated_status = brigand::int32_t<+1>;

  // Status for SIMD storage to be determined
  using unknown_status = brigand::int32_t<42>;

  /*!
    @ingroup group-detail
    @brief SIMD storage status

    Determines how a given block of @c C elements of type @c T should fit in the
    hardware registers proposed by extension @c X.
  **/
  template< typename T, std::size_t C, typename X>
  struct storage_status : brigand::int32_t<   (expected_cardinal<T,X>::value!=C)
                                        * ( (expected_cardinal<T,X>::value<C) ? +1 : -1)
                                      >
  {};

  // If ABI is not supported by current hardware, search for proper emulated storage later
  template< typename T, std::size_t C>
  struct  storage_status<T,C,simd_emulation_> : unknown_status
  {};

  /*!
    @ingroup  group-detail
    @brief    Storage type for SIMD data

    For a given couple @c Type x @c Cardinal, provides the type usbale for storing a block
    containing @c Cardinal elements of type @c Type in an optimized way.

    @tparam Type      Type of the stored elements
    @tparam Cardinal  Number of element stored
  **/
  template< typename Type, std::size_t Cardinal, typename ABI
          , typename Status = typename storage_status<Type,Cardinal,ABI>::type
          , typename Enable = void
          >
  struct storage_of
  {};

  // Unknown ABI requires checks on aggregation/emulation
  template< typename Type, std::size_t Cardinal>
  struct  storage_of<Type,Cardinal,simd_emulation_,unknown_status>
        : storage_of<Type,Cardinal,BOOST_SIMD_DEFAULT_FAMILY>
  {};

  // If the cardinal requested is lower than the expected one,
  // then try to find a suitable storage in parent extension.
  template< typename Type, std::size_t Cardinal, typename ABI>
  struct  storage_of<Type,Cardinal,ABI,emulated_status>
        : storage_of<Type,Cardinal, typename limits<ABI>::parent>
  {};

  // If the cardinal requested is lower than the expected one and no extension fits,
  // then use an array of scalar.
  template< typename Type, std::size_t Cardinal>
  struct storage_of<Type,Cardinal,boost::simd::simd_,emulated_status>
  {
    using type = std::array<Type,Cardinal>;
  };

  // If we match cardinals, use as_simd for current Familly unless Type is no_such_type_
  template< typename Type, std::size_t Cardinal, typename ABI>
  struct storage_of<Type,Cardinal,ABI,native_status>
  {
    using parent = storage_of<Type,Cardinal,typename limits<ABI>::parent>;
    using base   = boost::simd::detail::as_simd<Type,ABI>;
    using type   = typename std::conditional< std::is_same< typename base::type
                                                          , brigand::no_such_type_
                                                          >::value
                                            , parent
                                            , base
                                            >::type::type;
  };

  // IF we request more than needed, we aggregate exactly 2 smaller SIMD registers
  template< typename Type, std::size_t Cardinal, typename ABI>
  struct storage_of<Type,Cardinal,ABI,aggregated_status>
  {
    using base = pack<Type,Cardinal/2>;
    using type = std::array<base,2>;
  };
} } }

#endif
