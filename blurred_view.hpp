/*
 * Distributed under the Boost Software License, Version 1.0.(See accompanying 
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt.)
 *
 * File:        waterfront/blurred_view.hpp
 * Date:        Sun Feb 03 14:10:28 MST 2008
 * Copyright:   2008 CodeRage, LLC
 * Author:      Jonathan Turkanis
 * Contact:     turkanis at coderage dot com
 *
 * Defines the class blurred_view.
 */

#ifndef WATERFRONT_BLURRED_VIEW_HPP_INCLUDED
#define WATERFRONT_BLURRED_VIEW_HPP_INCLUDED

#include <cmath>  // ceil
#include "ball.hpp"
#include "point.hpp"
#include "simple_map.hpp"

namespace waterfront {

// Simple map that includes all the cells of a map 
// specified at construction plus all the cells with a
// specified distance of a cell in specified map.
class blurred_view : public simple_map {
public:
    template<typename Map>
    blurred_view(Map& map, double radius) 
        : simple_map(map.columns(), map.rows(), map.scale())
    {
        int    offset = static_cast<int>(std::ceil(radius / map.scale() - 0.5));
        int    width = offset * 2 + 1;
        point  center( map.scale() * (width + 1) / 2,
                       map.scale() * (width + 1) / 2 );
        ball disc( width, width, map.scale(), center, radius );
        for (int a = 0, rows = map.rows(); a < rows; ++a) {
            for (int b = 0, cols = map.columns(); b < cols; ++b) {
                if (!map[b][a])
                    continue;
                for (int c = a - offset; c <= a + offset; ++c) {
                    if (c < 0 || c >= rows)
                        continue;
                    for (int d = b - offset; d <= b + offset; ++d) {
                        if (d < 0 || d >= cols)
                            continue;
                        if (disc[d - b + offset][a - c + offset])
                            (*this)[d][c] = true;
                    }
                }
            }
        }
    }
};

} // End namespace waterfront.

#endif // #ifndef WATERFRONT_BLURRED_VIEW_HPP_INCLUDED
