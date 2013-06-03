/*
 * Distributed under the Boost Software License, Version 1.0.(See accompanying 
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt.)
 *
 * File:        waterfront/point.hpp
 * Date:        Sun Feb 03 14:10:28 MST 2008
 * Copyright:   2008 CodeRage, LLC
 * Author:      Jonathan Turkanis
 * Contact:     turkanis at coderage dot com
 *
 * Defines the class point, representing a location in a map.
 */

#ifndef WATERFRONT_POINT_HPP_INCLUDED
#define WATERFRONT_POINT_HPP_INCLUDED

namespace waterfront {

class point {
public:
    explicit point(double x = 0, double y = 0) : x_(x), y_(y) { }
    double x() const { return x_; }
    double y() const { return y_; }
    void set(double x, double y) { x_ = x; y_ = y; }
    void set_x(double x) { x_ = x; }
    void set_y(double y) { y_ = y; }
private:
    double x_;
    double y_;
};

} // End namespace waterfront.

#endif // #ifndef WATERFRONT_POINT_HPP_INCLUDED
