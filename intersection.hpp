/*
 * Distributed under the Boost Software License, Version 1.0.(See accompanying 
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt.)
 *
 * File:        waterfront/intersection.hpp
 * Date:        Sun Feb 03 14:10:28 MST 2008
 * Copyright:   2008 CodeRage, LLC
 * Author:      Jonathan Turkanis
 * Contact:     turkanis at coderage dot com
 *
 * Defines the class template intersection taking two models of Map and 
 * generating a third Model of map whose land mass is the union of the two 
 * component maps. 
 */

#ifndef WATERFRONT_INTERSECTION_HPP_INCLUDED
#define WATERFRONT_INTERSECTION_HPP_INCLUDED

#include <stdexcept>
#include "map_base.hpp"

namespace waterfront {

template<typename First, typename Second>
class intersection : public map_base< intersection<First, Second> > {
public:
    friend class map_base< intersection<First, Second> >;
    typedef map_base< intersection<First, Second> > base_type;
    intersection(First& first, Second& second) 
        : base_type(first.columns(), first.rows(), first.scale()), 
          first_(first), second_(second)
    { 
        if ( first.columns() != second.columns() ||
             first.rows() != second.rows() || 
             first.scale() != second.scale() )
        {
            throw std::logic_error(
                      "can't form the union of two maps unless they "
                      "have the same dimensions and scale"
                  );
        }
    }
private:
    bool at(int col, int row) const
    {
        return first_[col][row] && second_[col][row];
    }
    First&   first_;
    Second&  second_;
};

} // End namespace waterfront.

#endif // #ifndef WATERFRONT_INTERSECTION_HPP_INCLUDED
