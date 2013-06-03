/*
 * Distributed under the Boost Software License, Version 1.0.(See accompanying 
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt.)
 *
 * File:        waterfront/coastal_view.hpp
 * Date:        Sun Feb 03 14:10:28 MST 2008
 * Copyright:   2008 CodeRage, LLC
 * Author:      Jonathan Turkanis
 * Contact:     turkanis at coderage dot com
 *
 * Defines the class coastal_view, taking a map and generating a second
 * map consisting of the cells in the first map that are sufficiently
 * close to the coastline.
 */

#ifndef WATERFRONT_COASTAL_VIEW_HPP_INCLUDED
#define WATERFRONT_COASTAL_VIEW_HPP_INCLUDED

#include <cmath>  // ceil
#include "blurred_view.hpp"
#include "intersection.hpp"
#include "inverse.hpp"

namespace waterfront {

namespace detail {

template<typename Map>
class coastal_view_impl {
protected:
    coastal_view_impl(Map& m, double distance)
        : inverse_(m), blurred_(inverse_, distance)
        { }
private:
    inverse<Map>  inverse_;
protected:
    blurred_view  blurred_;
};

} // End namespace detail.

template<typename Map>
class coastal_view 
    : public detail::coastal_view_impl<Map>,
      public intersection<Map, blurred_view>
{
public:
    typedef intersection<Map, blurred_view> base_type;

    // Base-from-member idiom
    coastal_view(Map& map, double distance) 
        : detail::coastal_view_impl<Map>(map, distance),
          base_type(map, detail::coastal_view_impl<Map>::blurred_)
        { }
};

} // End namespace waterfront.

#endif // #ifndef WATERFRONT_COASTAL_VIEW_HPP_INCLUDED
