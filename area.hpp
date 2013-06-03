/*
 * Distributed under the Boost Software License, Version 1.0.(See accompanying 
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt.)
 *
 * File:        waterfront/area.hpp
 * Date:        Sun Feb 03 14:10:28 MST 2008
 * Copyright:   2008 CodeRage, LLC
 * Author:      Jonathan Turkanis
 * Contact:     turkanis at coderage dot com
 *
 * Defines the function template area returning a map's total land
 * area.
 */

#ifndef WATERFRONT_AREA_HPP_INCLUDED
#define WATERFRONT_AREA_HPP_INCLUDED

#include <stdexcept>
#include "map_base.hpp"

namespace waterfront {

template<typename Map>
double area(const Map& map)
{
    int count = 0;
    for (int w = 0, m = map.rows(); w < m; ++w)
        for (int z = 0, n = map.columns(); z < n; ++z)
            if (map[z][w])
                ++count;
    return count * map.scale() * map.scale();
}

} // End namespace waterfront.

#endif // #ifndef WATERFRONT_AREA_HPP_INCLUDED
