/*
 * Distributed under the Boost Software License, Version 1.0.(See accompanying 
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt.)
 *
 * File:        waterfront/refinement.hpp
 * Date:        Sun Feb 03 14:10:28 MST 2008
 * Copyright:   2008 CodeRage, LLC
 * Author:      Jonathan Turkanis
 * Contact:     turkanis at coderage dot com
 *
 * Defines the class template refinement taking a model or Map and
 * generating a second model of Map by subdividing each cell of the
 * original map.
 */

#ifndef WATERFRONT_REFINEMENT_HPP_INCLUDED
#define WATERFRONT_REFINEMENT_HPP_INCLUDED

#include <cmath>
#include "map_base.hpp"

namespace waterfront {

template<typename Map>
class refinement : public map_base< refinement<Map> > {
public:
    friend class map_base< refinement<Map> >;
    typedef map_base< refinement<Map> > base_type;
    refinement(Map& map, int resolution) 
        : base_type(
              map.columns() * resolution, 
              map.rows() * resolution, 
              map.scale() / resolution 
          ),
          map_(map), resolution_(resolution) 
        { }
private:
    bool at(int col, int row) const
    {
        int c = floor(col / resolution_);
        int r = floor(row / resolution_);
        return map_[c][r];
    }
    static int floor(double d)
    {
        return static_cast<int>(std::floor(d));
    }
    Map&  map_;
    int   resolution_;
};

} // End namespace waterfront.

#endif // #ifndef WATERFRONT_REFINEMENT_HPP_INCLUDED
