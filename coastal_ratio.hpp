/*
 * Distributed under the Boost Software License, Version 1.0.(See accompanying 
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt.)
 *
 * File:        waterfront/coastal_ratio.hpp
 * Date:        Sun Feb 03 14:10:28 MST 2008
 * Copyright:   2008 CodeRage, LLC
 * Author:      Jonathan Turkanis
 * Contact:     turkanis at coderage dot com
 *
 * Defines the function template coastal_ratio taking a map m, a distance d, and 
 * a precision and returning the fraction of the land mass of m that is within d
 * of water.
 */

#ifndef WATERFRONT_COASTAL_RATIO_HPP_INCLUDED
#define WATERFRONT_COASTAL_RATIO_HPP_INCLUDED

#include <cmath>
#include "area.hpp"
#include "coastal_view.hpp"
#include "refinement.hpp"

namespace waterfront {

template<typename Map>
double coastal_ratio(Map& map, double dist, double precision)
{
    int resolution = 
        static_cast<int>(std::ceil(map.scale() / precision));
    refinement<Map>      ref(map, resolution);
    coastal_view< 
        refinement<Map>
    >                    coastal(ref, dist);
    return area(coastal) / area(map);
}

} // End namespace waterfront.

#endif // #ifndef WATERFRONT_COASTAL_RATIO_HPP_INCLUDED
