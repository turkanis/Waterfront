/*
 * Distributed under the Boost Software License, Version 1.0.(See accompanying 
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt.)
 *
 * File:        waterfront/ball.hpp
 * Date:        Sun Feb 03 14:10:28 MST 2008
 * Copyright:   2008 CodeRage, LLC
 * Author:      Jonathan Turkanis
 * Contact:     turkanis at coderage dot com
 *
 * Defines the class model, a model of map whose land mass is determined
 * as the set of cells within a certain distance of a specified cell.
 */

#ifndef WATERFRONT_BALL_HPP_INCLUDED
#define WATERFRONT_BALL_HPP_INCLUDED

#include "distance.hpp"
#include "map_base.hpp"
#include "point.hpp"

namespace waterfront {

class ball : public map_base<ball> {
public:
    friend class map_base<ball>;
    ball(int cols, int rows, double scale, point center, double diameter)
        : map_base<ball>(cols, rows, scale), center_(center), diameter_(diameter)
        { }
private:
    bool at(int col, int row) const
    {
        point p( (2 * col + 1) * this->scale() / 2, 
                 (2 * row + 1) * this->scale() / 2 );
        return distance(p, center_) <= diameter_;
    }
    point   center_;
    double  diameter_;
};

} // End namespace waterfront.

#endif // #ifndef WATERFRONT_BALL_HPP_INCLUDED
