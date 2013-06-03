/*
 * Distributed under the Boost Software License, Version 1.0.(See accompanying 
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt.)
 *
 * File:        waterfront/map_base.hpp
 * Date:        Sun Feb 03 14:10:28 MST 2008
 * Copyright:   2008 CodeRage, LLC
 * Author:      Jonathan Turkanis
 * Contact:     turkanis at coderage dot com
 *
 * Defines the class template map_base, a base class for defining models of Map.
 */

#ifndef WATERFRONT_MAP_BASE_HPP_INCLUDED
#define WATERFRONT_MAP_BASE_HPP_INCLUDED

#include <cassert>

namespace waterfront {

template<typename Derived>
class map_base {
private:
    class column_type;
public:
    int columns() const { return cols_; }
    int rows() const { return rows_; }
    double scale() const { return scale_; }
    column_type operator[](int col) const;
protected:
    map_base(int cols, int rows, double scale)
        : cols_(cols), rows_(rows), scale_(scale)
        { }
private:

    // Prohibit copying and assignment
    map_base(const map_base&);
    map_base& operator=(const map_base&);

    static bool at(const Derived& d, int col, int row)
    {
        return d.at(col, row);
    }

    class column_type {
    public:
        column_type(const Derived& derived, int col)
            : derived_(derived), col_(col)
            { }
        bool operator[](int row) const
        {
            assert(col_ < derived_.columns() && row < derived_.rows());
            return map_base::at(derived_, col_, row);
        }
    private:
        const Derived&  derived_;
        int             col_;
    };
    friend class column_type;

    int     cols_;
    int     rows_;
    double  scale_;
};

template<typename Derived>
typename map_base<Derived>::column_type
map_base<Derived>::operator[] (int col) const
{
    return column_type(static_cast<const Derived&>(*this), col);
}

} // End namespace waterfront.

#endif // #ifndef WATERFRONT_MAP_BASE_HPP_INCLUDED
