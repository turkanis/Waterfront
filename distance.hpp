/*
 * Distributed under the Boost Software License, Version 1.0.(See accompanying 
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt.)
 *
 * File:        waterfront/distance.hpp
 * Date:        Sun Feb 03 14:10:28 MST 2008
 * Copyright:   2008 CodeRage, LLC
 * Author:      Jonathan Turkanis
 * Contact:     turkanis at coderage dot com
 *
 * Defines the function overloaded function distance, returning the 
 * distance between two points.
 */

#ifndef WATERFRONT_DISTANCE_HPP_INCLUDED
#define WATERFRONT_DISTANCE_HPP_INCLUDED

#include <cmath>
#include "point.hpp"

namespace waterfront {

inline double distance(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

inline double distance(const point& p1, const point& p2)
{
    return distance(p1.x(), p1.y(), p2.x(), p2.y());
}

} // End namespace waterfront.

#endif // #ifndef WATERFRONT_DISTANCE_HPP_INCLUDED
