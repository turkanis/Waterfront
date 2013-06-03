/*
 * Distributed under the Boost Software License, Version 1.0.(See accompanying 
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt.)
 *
 * File:        waterfront/inverse.hpp
 * Date:        Sun Feb 03 14:10:28 MST 2008
 * Copyright:   2008 CodeRage, LLC
 * Author:      Jonathan Turkanis
 * Contact:     turkanis at coderage dot com
 *
 * Defines the class template inverse taking a model of Map and generating a 
 * second model of Map by replacing land with water and vice versa.
 */

#ifndef WATERFRONT_INVERSE_HPP_INCLUDED
#define WATERFRONT_INVERSE_HPP_INCLUDED

#include "map_base.hpp"

namespace waterfront {

template<typename Map>
class inverse : public map_base< inverse<Map> > {
public:
    friend class map_base< inverse<Map> >;
    typedef map_base< inverse<Map> > base_type;
    inverse(Map& map) 
        : base_type(map.columns(), map.rows(), map.scale()), 
          map_(map) 
        { }
private:
    bool at(int col, int row) const
    {
        return !map_[col][row];
    }
    Map& map_;
};

} // End namespace waterfront.

#endif // #ifndef WATERFRONT_INVERSE_HPP_INCLUDED
